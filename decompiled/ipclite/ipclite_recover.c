__int64 __fastcall ipclite_recover(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 (*v8)(void); // x8
  __int64 result; // x0
  char v10; // [xsp+0h] [xbp+0h]

  v8 = (__int64 (*)(void))off_E470;
  if ( off_E470 )
  {
    if ( *((_DWORD *)off_E470 - 1) != -1966529501 )
      __break(0x8228u);
    return v8();
  }
  else
  {
    if ( (ipclite_debug_level & 1) == 0 )
      return result;
    if ( (ipclite_debug_control & 1) != 0 )
    {
      result = printk(&unk_FF4F, "ipclite", "ipclite_recover");
      if ( (ipclite_debug_control & 4) == 0 )
        return result;
    }
    else if ( (ipclite_debug_control & 4) == 0 )
    {
      return result;
    }
    return ipclite_inmem_log(
             "APPS:%s:Unassigned function : %s",
             (__int64)"ERR",
             (__int64)"ipclite_recover",
             a4,
             a5,
             a6,
             a7,
             a8,
             v10);
  }
}
