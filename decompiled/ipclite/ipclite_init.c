__int64 __fastcall ipclite_init(
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
  char v10; // [xsp+0h] [xbp+0h]

  v8 = (__int64 (*)(void))api_list_t;
  if ( !api_list_t )
  {
    if ( (ipclite_debug_level & 1) != 0 )
    {
      if ( (ipclite_debug_control & 1) != 0 )
      {
        printk(&unk_FF4F, "ipclite", "ipclite_init");
        if ( (ipclite_debug_control & 4) == 0 )
          return 4294967274LL;
        goto LABEL_8;
      }
      if ( (ipclite_debug_control & 4) != 0 )
LABEL_8:
        ipclite_inmem_log(
          "APPS:%s:Unassigned function : %s",
          (__int64)"ERR",
          (__int64)"ipclite_init",
          a4,
          a5,
          a6,
          a7,
          a8,
          v10);
    }
    return 4294967274LL;
  }
  if ( *((_DWORD *)api_list_t - 1) != -939997060 )
    __break(0x8228u);
  return v8();
}
