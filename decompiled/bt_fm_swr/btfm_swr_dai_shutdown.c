__int64 __fastcall btfm_swr_dai_shutdown(__int64 a1, unsigned int a2)
{
  __int64 v3; // x20
  __int64 v4; // x8

  v3 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  printk(&unk_7767, "btfm_swr_dai_shutdown");
  if ( !v3 )
    return printk(&unk_78AC, "btfm_swr_dai_shutdown");
  v4 = *(_QWORD *)(v3 + 40);
  if ( !v4 )
    return printk(&unk_78AC, "btfm_swr_dai_shutdown");
  if ( a2 >= 5 )
    return printk(&unk_720F, "btfm_swr_dai_shutdown");
  return btfm_swr_disable_port(
           *(_BYTE *)(v4 + 24LL * a2 + 24),
           *(_BYTE *)(v3 + 30),
           0x686765666BuLL >> (8 * (unsigned __int8)a2));
}
