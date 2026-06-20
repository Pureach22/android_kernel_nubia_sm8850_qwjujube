__int64 __fastcall dwc3_msm_pm_suspend(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  void (*v3)(void); // x8
  __int64 v4; // x0
  void (*v5)(void); // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 152);
  if ( !*(_QWORD *)(v1 + 40) )
  {
LABEL_16:
    result = dwc3_msm_suspend(v1, 1);
    if ( !(_DWORD)result )
      *(_DWORD *)(v1 + 512) = 1;
    return result;
  }
  dwc3_dbg_print(*(_QWORD *)(v1 + 1256), 0xFFu, "PM Sus", 0, (const char *)&unk_16A05);
  if ( *(_BYTE *)(v1 + 757) == 1 && (*(_BYTE *)(v1 + 736) & 1) != 0 )
  {
    v2 = *(_QWORD *)(v1 + 448);
    if ( v2 )
    {
      v3 = *(void (**)(void))(v2 + 320);
      if ( !v3 )
        goto LABEL_9;
      if ( *((_DWORD *)v3 - 1) != -1429527844 )
        __break(0x8228u);
      v3();
      v2 = *(_QWORD *)(v1 + 448);
      if ( v2 )
LABEL_9:
        *(_DWORD *)(v2 + 16) &= ~1u;
    }
    v4 = *(_QWORD *)(v1 + 456);
    if ( v4 )
    {
      v5 = *(void (**)(void))(v4 + 320);
      if ( !v5 )
        goto LABEL_15;
      if ( *((_DWORD *)v5 - 1) != -1429527844 )
        __break(0x8228u);
      v5();
      v4 = *(_QWORD *)(v1 + 456);
      if ( v4 )
LABEL_15:
        *(_DWORD *)(v4 + 16) &= ~1u;
    }
    goto LABEL_16;
  }
  if ( *(_DWORD *)(v1 + 832) )
  {
    result = 0;
    *(_DWORD *)(v1 + 512) = 1;
  }
  else
  {
    dev_err(*(_QWORD *)v1, "Abort PM suspend!! (USB is outside LPM)\n");
    return 4294967280LL;
  }
  return result;
}
