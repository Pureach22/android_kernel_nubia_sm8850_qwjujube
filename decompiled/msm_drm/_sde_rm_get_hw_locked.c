__int64 __fastcall sde_rm_get_hw_locked(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // x4
  __int64 v4; // x9
  __int64 v5; // x8
  int v6; // w6
  __int64 v7; // x10
  __int64 v8; // x10

  if ( a1 && a2 && (v3 = *(unsigned int *)(a2 + 20), (unsigned int)v3 < 0xF) )
  {
    v4 = *(_QWORD *)(a2 + 8);
    *(_QWORD *)a2 = 0;
    v5 = a1 + 16 * v3 + 24;
    if ( v4 && v4 == v5 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "attempt resume iteration past last\n");
    }
    else
    {
      if ( !v4 )
        v4 = a1 + 16 * v3 + 24;
      *(_QWORD *)(a2 + 8) = v4;
      if ( (a3 & 1) != 0 )
      {
        while ( 1 )
        {
          v4 = *(_QWORD *)v4;
          *(_QWORD *)(a2 + 8) = v4;
          if ( v4 == v5 )
            break;
          if ( *(_DWORD *)(v4 + 32) != (_DWORD)v3 )
            goto LABEL_29;
          v6 = *(_DWORD *)(a2 + 16);
          if ( v6 )
          {
            v7 = *(_QWORD *)(v4 + 16);
            if ( !v7 || *(_DWORD *)(v7 + 20) != v6 )
              continue;
          }
          goto LABEL_22;
        }
      }
      else
      {
        while ( 1 )
        {
          v4 = *(_QWORD *)(v4 + 8);
          *(_QWORD *)(a2 + 8) = v4;
          if ( v4 == v5 )
            break;
          if ( *(_DWORD *)(v4 + 32) != (_DWORD)v3 )
          {
LABEL_29:
            printk(&unk_262490, "_sde_rm_get_hw_locked");
            return 0;
          }
          v6 = *(_DWORD *)(a2 + 16);
          if ( v6 )
          {
            v8 = *(_QWORD *)(v4 + 16);
            if ( !v8 || *(_DWORD *)(v8 + 20) != v6 )
              continue;
          }
LABEL_22:
          *(_QWORD *)a2 = *(_QWORD *)(v4 + 40);
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "found type %d id %d for enc %d\n", v3, *(_DWORD *)(v4 + 36), v6);
          return 1;
        }
      }
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "no match, type %d for enc %d\n", v3, *(_DWORD *)(a2 + 16));
    }
  }
  else
  {
    printk(&unk_26246B, "_sde_rm_get_hw_locked");
  }
  return 0;
}
