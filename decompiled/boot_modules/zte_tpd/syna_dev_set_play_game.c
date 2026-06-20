__int64 __fastcall syna_dev_set_play_game(_QWORD *a1, unsigned int a2, unsigned int a3)
{
  int v6; // w0

  printk(&unk_35F27, "syna_dev_set_play_game", a2);
  if ( !a1 )
    return 4294967274LL;
  v6 = syna_tcm_set_dynamic_config(*a1, 213, a2 | (2 * a2), a3);
  return v6 & (unsigned int)(v6 >> 31);
}
