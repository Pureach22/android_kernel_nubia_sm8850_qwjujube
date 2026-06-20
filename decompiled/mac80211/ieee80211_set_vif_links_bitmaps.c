__int64 __fastcall ieee80211_set_vif_links_bitmaps(__int64 result, unsigned __int16 a2, int a3)
{
  int v3; // w8
  __int64 v4; // x19

  *(_WORD *)(result + 5800) = a2;
  *(_WORD *)(result + 5804) = a3;
  if ( !a2 )
    goto LABEL_13;
  if ( ((unsigned __int16)a3 & ~a2) != 0 || (a2 & ~a3) == 0 )
  {
    v4 = result;
    _warn_printk("Invalid links: valid=0x%x, dormant=0x%x", a2, (unsigned __int16)a3);
    result = v4;
    __break(0x800u);
LABEL_13:
    *(_DWORD *)(result + 5802) = 0;
    return result;
  }
  v3 = *(_DWORD *)(result + 4720);
  if ( v3 == 2 )
  {
    if ( !*(_WORD *)(result + 5802) )
    {
      *(_WORD *)(result + 5802) = a2 & ~(_WORD)a3;
      result = _sw_hweight16((unsigned __int16)(a2 & ~(_WORD)a3));
      if ( (unsigned int)result >= 2 )
        goto LABEL_7;
    }
  }
  else if ( v3 != 3 || (*(_WORD *)(result + 5802) = a2, (_WORD)a3) )
  {
LABEL_7:
    __break(0x800u);
  }
  return result;
}
