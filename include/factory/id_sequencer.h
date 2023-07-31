#pragma once

typedef struct id_sequencer id_sequencer;

id_sequencer *sequencer_create();

void sequencer_destroy(id_sequencer *s);

size_t sequencer_get_id(id_sequencer *s);
