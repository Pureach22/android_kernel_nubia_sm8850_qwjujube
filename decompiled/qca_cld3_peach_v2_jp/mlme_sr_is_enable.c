__int64 __fastcall mlme_sr_is_enable(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 cmpt_obj; // x0
  unsigned int v10; // w8

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !cmpt_obj )
    return 1;
  v10 = *(unsigned __int8 *)(cmpt_obj + 182);
  if ( !*(_BYTE *)(cmpt_obj + 182) )
    return 1;
  if ( (v10 & 2) != 0 )
    return (v10 >> 3) & 1;
  return 1;
}
