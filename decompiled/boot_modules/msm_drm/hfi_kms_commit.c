__int64 __fastcall hfi_kms_commit(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x23
  __int64 v7; // x24
  __int64 v8; // x9
  __int64 v9; // x21
  __int64 v10; // x22

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v5 = *(_QWORD *)(a2 + 8);
    if ( *(int *)(v5 + 860) >= 1 )
    {
      v6 = 0;
      v7 = 0;
      do
      {
        v8 = *(_QWORD *)(a2 + 32);
        v9 = *(_QWORD *)(v8 + v6);
        if ( v9 )
        {
          v10 = *(_QWORD *)(v8 + v6 + 24);
          if ( (*(_BYTE *)(*(_QWORD *)(v9 + 2008) + 9LL) & 1) != 0 || *(_BYTE *)(v10 + 9) == 1 )
          {
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, " crtc:%d\n", *(_DWORD *)(v9 + 112));
            sde_crtc_commit_kickoff(v9, v10);
            v5 = *(_QWORD *)(a2 + 8);
          }
        }
        ++v7;
        v6 += 56;
      }
      while ( v7 < *(int *)(v5 + 860) );
    }
    return 0;
  }
  return result;
}
