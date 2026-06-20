__int64 __fastcall wlan_mlme_get_aid_count(
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
  __int64 v10; // x8
  unsigned __int64 v11; // x10
  __int64 result; // x0
  __int64 v13; // x11

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !cmpt_obj )
    return 0xFFFF;
  v10 = *(_QWORD *)(cmpt_obj + 248);
  if ( !v10 )
    return 0xFFFF;
  if ( !*(_WORD *)(v10 + 258) )
    return 0;
  v11 = 0;
  LODWORD(result) = 0;
  do
  {
    v13 = *(_QWORD *)(v10 + ((v11 >> 3) & 0x1FFFFFFFFFFFFFF8LL)) >> v11;
    ++v11;
    result = (unsigned int)result + (v13 & 1);
  }
  while ( *(unsigned __int16 *)(v10 + 258) != v11 );
  return result;
}
