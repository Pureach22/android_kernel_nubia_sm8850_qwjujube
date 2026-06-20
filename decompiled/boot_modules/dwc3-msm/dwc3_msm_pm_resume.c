__int64 __fastcall dwc3_msm_pm_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x0
  void (*v4)(void); // x8
  __int64 v5; // x8
  _DWORD *v6; // x8
  __int64 v7; // x8
  __int64 v8; // x0
  void (*v9)(void); // x8

  v1 = *(_QWORD *)(a1 + 152);
  dwc3_dbg_print(*(_QWORD *)(v1 + 1256), 0xFFu, "PM Res", 0, (const char *)&unk_16A05);
  *(_DWORD *)(v1 + 512) = 0;
  if ( *(_BYTE *)(v1 + 736) == 1 && *(_BYTE *)(v1 + 757) == 1 )
  {
    v2 = *(_QWORD *)(v1 + 448);
    if ( v2 )
    {
      *(_DWORD *)(v2 + 16) |= 1u;
      v3 = *(_QWORD *)(v1 + 448);
      if ( v3 )
      {
        v4 = *(void (**)(void))(v3 + 312);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != -1429527844 )
            __break(0x8228u);
          v4();
        }
      }
    }
    v5 = *(_QWORD *)(v1 + 40);
    if ( v5 )
      v6 = (_DWORD *)(*(_QWORD *)(v5 + 168) + 1232LL);
    else
      v6 = (_DWORD *)(v1 + 1128);
    if ( *v6 >= 5u )
    {
      v7 = *(_QWORD *)(v1 + 456);
      if ( v7 )
      {
        *(_DWORD *)(v7 + 16) |= 1u;
        v8 = *(_QWORD *)(v1 + 456);
        if ( v8 )
        {
          v9 = *(void (**)(void))(v8 + 312);
          if ( v9 )
          {
            if ( *((_DWORD *)v9 - 1) != -1429527844 )
              __break(0x8228u);
            v9();
          }
        }
      }
    }
  }
  return 0;
}
