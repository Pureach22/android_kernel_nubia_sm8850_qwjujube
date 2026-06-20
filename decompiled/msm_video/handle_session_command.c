__int64 __fastcall handle_session_command(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  unsigned int v3; // w8
  __int64 (*v4)(void); // x8

  v2 = *(unsigned int *)(a2 + 4);
  v3 = v2 - 16777219;
  if ( (unsigned int)(v2 - 16777219) <= 0xF && ((0xCBFFu >> v3) & 1) != 0 )
  {
    v4 = *((__int64 (**)(void))*(&off_9E318 + v3) + 1);
    if ( *((_DWORD *)v4 - 1) != 503439326 )
      __break(0x8228u);
    return v4();
  }
  else
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_86030, "err ", a1 + 340, "handle_session_command", v2);
    return 4294967274LL;
  }
}
