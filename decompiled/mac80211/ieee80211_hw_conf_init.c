__int64 __fastcall ieee80211_hw_conf_init(__int64 result)
{
  __int64 v1; // x20

  if ( !*(_DWORD *)(result + 1316) )
    goto LABEL_5;
  if ( *(_BYTE *)(result + 1400) == 1 )
  {
    v1 = result;
    ieee80211_calc_hw_conf_chan();
    result = v1;
  }
  result = drv_config(result);
  if ( (_DWORD)result )
LABEL_5:
    __break(0x800u);
  return result;
}
