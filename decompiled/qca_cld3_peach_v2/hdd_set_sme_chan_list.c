__int64 __fastcall hdd_set_sme_chan_list(__int64 a1)
{
  return sme_init_chan_list(*(_QWORD *)(a1 + 16), *(unsigned int *)(a1 + 632));
}
