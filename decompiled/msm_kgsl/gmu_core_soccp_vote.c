__int64 __fastcall gmu_core_soccp_vote(__int64 a1, char a2)
{
  int v4; // w0
  __int64 v6; // x8
  unsigned int v7; // w19
  const char *v8; // x2
  unsigned __int64 v15; // x9

  if ( ((*(_QWORD *)(a1 + 1528) >> 9) & 1) == (a2 & 1) )
    return 0;
  v4 = kgsl_hw_fence_soccp_vote();
  if ( !v4 )
  {
    _X8 = (unsigned __int64 *)(a1 + 1528);
    __asm { PRFM            #0x11, [X8] }
    do
      v15 = __ldxr(_X8);
    while ( __stxr(v15 ^ 0x200, _X8) );
    return 0;
  }
  v6 = *(_QWORD *)(a1 + 1544);
  v7 = v4;
  if ( (a2 & 1) != 0 )
    v8 = "on";
  else
    v8 = "off";
  dev_err(v6 + 16, "soccp power %s failed: %d. Disabling hw fences\n", v8, v4);
  return v7;
}
