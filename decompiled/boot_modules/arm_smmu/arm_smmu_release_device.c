__int64 __fastcall arm_smmu_release_device(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x23
  __int64 **v3; // x20
  __int64 *v4; // x21
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 result; // x0
  unsigned int v8; // w25
  _QWORD **v9; // x22
  int v10; // w1
  __int64 v11; // x10
  int v12; // w9
  char v13; // w8
  int v14; // w11
  __int64 v15; // x19
  __int64 v16; // x10
  int v17; // w11
  __int64 v18; // x8
  __int64 v19; // x8
  void (__fastcall *v20)(_QWORD); // x10
  __int64 v21; // x8
  __int64 v22; // x9
  unsigned int v23; // w9
  __int64 v24; // x3
  __int64 v25; // x10
  unsigned int v26; // w9
  __int64 v27; // x2
  _DWORD *v28; // x8
  unsigned __int16 *v29; // x8
  __int64 v30; // x3
  __int64 v31; // x8
  __int64 v32; // x2
  _DWORD *v33; // x8
  __int64 v34; // x0
  __int64 *v35; // x19
  __int64 v36; // x21
  unsigned int v37; // w8
  unsigned int v44; // w10
  __int64 v45; // [xsp+8h] [xbp-8h]

  v1 = *(_QWORD *)(a1 + 824);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 56);
    v3 = *(__int64 ***)(v1 + 72);
  }
  else
  {
    v2 = 0;
    v3 = nullptr;
  }
  v4 = *v3;
  v5 = **v3;
  if ( (*(_WORD *)(v5 + 488) & 7) == 0 )
  {
    v6 = a1;
    result = _pm_runtime_resume(**v3, 4);
    if ( (result & 0x80000000) != 0 )
    {
      v37 = *(_DWORD *)(v5 + 480);
      do
      {
        if ( !v37 )
          break;
        _X12 = (unsigned int *)(v5 + 480);
        __asm { PRFM            #0x11, [X12] }
        while ( 1 )
        {
          v44 = __ldxr(_X12);
          if ( v44 != v37 )
            break;
          if ( !__stlxr(v37 - 1, _X12) )
          {
            __dmb(0xBu);
            break;
          }
        }
        _ZF = v44 == v37;
        v37 = v44;
      }
      while ( !_ZF );
      return result;
    }
    v4 = *v3;
    a1 = v6;
  }
  v45 = a1;
  mutex_lock(v4 + 15);
  if ( *(_DWORD *)(v2 + 12) )
  {
    v8 = 0;
    v9 = v3 + 1;
    do
    {
      v10 = *((__int16 *)v9 + (int)v8);
      v11 = v4[14] + 24LL * *((__int16 *)v9 + (int)v8);
      v12 = *(unsigned __int8 *)(v11 + 21);
      v13 = *(_BYTE *)(v11 + 20);
      v14 = *(_DWORD *)(v11 + 8) - 1;
      *(_DWORD *)(v11 + 8) = v14;
      if ( !v14 )
      {
        v15 = v10;
        v16 = v4[14] + 24LL * v10;
        if ( disable_bypass )
          v17 = 2;
        else
          v17 = 1;
        *(_QWORD *)v16 = 0;
        *(_DWORD *)(v16 + 8) = 0;
        *(_DWORD *)(v16 + 12) = v17;
        *(_QWORD *)(v16 + 16) = 0;
        if ( v12 )
        {
          *(_BYTE *)(v4[14] + 24LL * v10 + 21) = 1;
          *(_BYTE *)(v4[14] + 24LL * v10 + 20) = v13;
        }
        else
        {
          v18 = v4[13];
          if ( v18 )
          {
            *(_BYTE *)(v18 + 8LL * v10 + 4) = 0;
            *(_BYTE *)(v4[13] + 8LL * v10 + 6) = 0;
          }
        }
        v19 = v4[6];
        if ( v19 )
        {
          v20 = *(void (__fastcall **)(_QWORD))(v19 + 136);
          if ( v20 )
          {
            if ( *((_DWORD *)v20 - 1) != -1998289792 )
              __break(0x822Au);
            v20(v4);
            v21 = v4[13];
            if ( !v21 )
              goto LABEL_10;
            goto LABEL_33;
          }
        }
        v22 = v4[14] + 24LL * v10;
        v23 = ((*(_DWORD *)(v22 + 12) & 3) << 16) & 0xFCFFFFFF
            | ((*(_DWORD *)(v22 + 16) & 3) << 24)
            | *(unsigned __int8 *)(v22 + 20);
        v24 = v23 | 0x300;
        if ( (*((_BYTE *)v4 + 33) & 0x10) != 0 )
        {
          v25 = v4[13];
          if ( v25 )
          {
            v26 = v23 | 0x700;
            if ( *(_BYTE *)(v25 + 8LL * v10 + 4) )
              v24 = v26;
            else
              v24 = (unsigned int)v24;
          }
        }
        v27 = 4LL * v10 + 3072;
        if ( v19 )
        {
          v28 = *(_DWORD **)(v19 + 8);
          if ( v28 )
          {
            if ( *(v28 - 1) != -1008624849 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64 *, _QWORD, __int64, __int64))v28)(v4, 0, v27, v24);
            v21 = v4[13];
            if ( !v21 )
              goto LABEL_10;
LABEL_33:
            v29 = (unsigned __int16 *)(v21 + 8 * v15);
            v30 = v29[1] | (*v29 << 16);
            if ( (*((_BYTE *)v4 + 33) & 0x10) == 0 )
            {
              if ( *((_BYTE *)v29 + 4) )
                v30 = (unsigned int)v30 | 0x80000000;
              else
                v30 = (unsigned int)v30;
            }
            v31 = v4[6];
            v32 = 4 * v15 + 2048;
            if ( v31 && (v33 = *(_DWORD **)(v31 + 8)) != nullptr )
            {
              if ( *(v33 - 1) != -1008624849 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64 *, _QWORD, __int64, __int64))v33)(v4, 0, v32, v30);
            }
            else
            {
              writel_relaxed_0(v30, (unsigned int *)(v4[1] + v32));
            }
            goto LABEL_10;
          }
        }
        writel_relaxed_0(v24, (unsigned int *)(v4[1] + v27));
        v21 = v4[13];
        if ( v21 )
          goto LABEL_33;
      }
LABEL_10:
      *((_WORD *)v9 + (int)v8++) = -1;
    }
    while ( v8 < *(_DWORD *)(v2 + 12) );
  }
  v34 = mutex_unlock(v4 + 15);
  v35 = *v3;
  v36 = **v3;
  if ( (*(_WORD *)(v36 + 488) & 7) == 0 )
  {
    *(_QWORD *)(v36 + 520) = ktime_get_mono_fast_ns(v34);
    _pm_runtime_suspend(*v35, 13);
  }
  kfree(v3);
  return iommu_logger_unregister(v45, 0);
}
