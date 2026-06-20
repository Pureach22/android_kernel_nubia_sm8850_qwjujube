__int64 __fastcall arm_smmu_attach_dev_type(__int64 a1, int a2)
{
  __int64 v2; // x8
  _QWORD **v3; // x25
  _QWORD *v4; // x19
  __int64 v5; // x22
  __int64 result; // x0
  __int64 v8; // x21
  __int64 v9; // x23
  unsigned int v10; // w8
  unsigned int v11; // w24
  _QWORD **v12; // x25
  int v13; // w1
  __int64 v14; // x9
  __int64 v15; // x8
  void (__fastcall *v16)(_QWORD); // x9
  __int64 v17; // x10
  unsigned int v18; // w10
  __int64 v19; // x3
  __int64 v20; // x11
  unsigned int v21; // w10
  __int64 v22; // x2
  _DWORD *v23; // x8
  __int64 v24; // x0
  __int64 v25; // x20

  v2 = *(_QWORD *)(a1 + 824);
  if ( !v2 )
    return 4294967277LL;
  v3 = *(_QWORD ***)(v2 + 72);
  if ( !v3 )
    return 4294967277LL;
  v4 = *v3;
  v5 = *(_QWORD *)(v2 + 56);
  result = arm_smmu_rpm_get(*v3);
  if ( (result & 0x80000000) == 0 )
  {
    v8 = (__int64)*v3;
    v9 = (*v3)[14];
    mutex_lock(*v3 + 15);
    v10 = *(_DWORD *)(v5 + 12);
    if ( v10 )
    {
      v11 = 0;
      v12 = v3 + 1;
      do
      {
        v13 = *((__int16 *)v12 + (int)v11);
        v14 = v9 + 24LL * *((__int16 *)v12 + (int)v11);
        if ( *(_DWORD *)(v14 + 12) != a2 || *(_BYTE *)(v14 + 20) )
        {
          *(_DWORD *)(v14 + 12) = a2;
          *(_DWORD *)(v14 + 16) = 0;
          *(_BYTE *)(v14 + 20) = 0;
          v15 = *(_QWORD *)(v8 + 48);
          if ( v15 && (v16 = *(void (__fastcall **)(_QWORD))(v15 + 136)) != nullptr )
          {
            if ( *((_DWORD *)v16 - 1) != -1998289792 )
              __break(0x8229u);
            v16(v8);
          }
          else
          {
            v17 = *(_QWORD *)(v8 + 112) + 24LL * v13;
            v18 = ((*(_DWORD *)(v17 + 12) & 3) << 16) & 0xFCFFFFFF
                | ((*(_DWORD *)(v17 + 16) & 3) << 24)
                | *(unsigned __int8 *)(v17 + 20);
            v19 = v18 | 0x300;
            if ( (*(_BYTE *)(v8 + 33) & 0x10) != 0 )
            {
              v20 = *(_QWORD *)(v8 + 104);
              if ( v20 )
              {
                v21 = v18 | 0x700;
                if ( *(_BYTE *)(v20 + 8LL * v13 + 4) )
                  v19 = v21;
                else
                  v19 = (unsigned int)v19;
              }
            }
            v22 = 4LL * v13 + 3072;
            if ( v15 && (v23 = *(_DWORD **)(v15 + 8)) != nullptr )
            {
              if ( *(v23 - 1) != -1008624849 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD, __int64, __int64))v23)(v8, 0, v22, v19);
            }
            else
            {
              writel_relaxed_0(v19, (unsigned int *)(*(_QWORD *)(v8 + 8) + v22));
            }
          }
          v10 = *(_DWORD *)(v5 + 12);
        }
        ++v11;
      }
      while ( v11 < v10 );
    }
    mutex_unlock(v8 + 120);
    pm_runtime_set_autosuspend_delay(*v4, 20);
    v24 = _pm_runtime_use_autosuspend(*v4, 1);
    if ( (*(_WORD *)(*v4 + 488LL) & 7) == 0 )
    {
      v25 = *v4;
      *(_QWORD *)(v25 + 520) = ktime_get_mono_fast_ns(v24);
      _pm_runtime_suspend(*v4, 13);
    }
    return 0;
  }
  return result;
}
