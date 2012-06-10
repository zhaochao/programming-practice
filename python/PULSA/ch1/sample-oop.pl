#!/usr/bin/perl

package Server;
use strict;

sub new {
    my $class = shift;
    my $self = {};
    $self->{IP} = shift;
    $self->{HOSTNAME} = shift;
    bless($self);

    return $self;
}

sub set_ip {
    my $self = shift;
    $self->{IP} = shift;
    
    return $self->{IP};
}

sub set_hostname {
    my $self = shift;
    $self->{HOSTNAME} = shift;

    return $self->{HOSTNAME};
}

sub ping {
    my $self = shift;
    my $extern_ip = shift;
    my $self_ip = $self->{IP};
    my $self_host = $self->{HOSTNAME};

    print "Pinging $extern_ip from $self_ip ($self_host)\n";
    return 0;
}

#package main;
my $server = Server->new('192.168.1.15', 'grumbly');
$server->ping('192.168.1.20');
