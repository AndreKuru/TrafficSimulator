#include "EventOccurrence.h"

bool EventOccurrence::operator>(const EventOccurrence other) {
    return time_>other.time_;
}

bool EventOccurrence::operator>=(const EventOccurrence other) {
    return time_>=other.time_;
}

bool EventOccurrence::operator<=(const EventOccurrence other) {
    return time_<=other.time_;
}

bool EventOccurrence::operator<(const EventOccurrence other) {
    return time_<other.time_;
}
