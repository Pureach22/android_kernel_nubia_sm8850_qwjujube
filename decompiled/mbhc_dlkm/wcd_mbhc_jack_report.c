__int64 __fastcall wcd_mbhc_jack_report(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  void *v7; // x0
  unsigned int v8; // w21

  if ( a1 + 392 == a2 )
  {
    v7 = &unk_DEBE;
LABEL_6:
    v8 = a3;
    printk(v7, "wcd_mbhc_jack_report");
    a3 = v8;
    return snd_soc_jack_report(a2, a3, a4);
  }
  if ( a1 + 568 == a2 )
  {
    v7 = &unk_E38D;
    goto LABEL_6;
  }
  return snd_soc_jack_report(a2, a3, a4);
}
