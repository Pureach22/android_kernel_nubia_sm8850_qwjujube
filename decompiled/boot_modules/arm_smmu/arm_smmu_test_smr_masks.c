__int64 __fastcall arm_smmu_test_smr_masks(__int64 result)
{
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x19
  int v4; // w10
  int v5; // w20
  __int64 v6; // x8
  __int64 v7; // x3
  _DWORD *v8; // x8
  _DWORD **v9; // x8
  _DWORD *v10; // x8
  int v11; // w0
  __int64 v12; // x8
  __int64 v13; // x3
  _DWORD *v14; // x8
  _DWORD **v15; // x8
  _DWORD *v16; // x8

  v1 = *(_QWORD *)(result + 104);
  if ( v1 )
  {
    v2 = *(_DWORD *)(result + 92);
    v3 = result;
    if ( v2 )
    {
      v4 = 0;
      v5 = 2048;
      while ( *(_BYTE *)(v1 + 8LL * v4 + 4) == 1 )
      {
        ++v4;
        v5 += 4;
        if ( v2 == v4 )
          return result;
      }
      v6 = *(_QWORD *)(result + 48);
      v7 = *(unsigned __int16 *)(result + 96);
      if ( v6 && (v8 = *(_DWORD **)(v6 + 8)) != nullptr )
      {
        if ( *(v8 - 1) != -1008624849 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v8)(result, 0, (unsigned int)v5, v7);
        v9 = *(_DWORD ***)(v3 + 48);
        if ( !v9 )
          goto LABEL_11;
      }
      else
      {
        writel_relaxed_0(*(unsigned __int16 *)(result + 96), (unsigned int *)(*(_QWORD *)(result + 8) + v5));
        v9 = *(_DWORD ***)(v3 + 48);
        if ( !v9 )
          goto LABEL_11;
      }
      v10 = *v9;
      if ( v10 )
      {
        if ( *(v10 - 1) != 616069899 )
          __break(0x8228u);
        v11 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v10)(v3, 0, (unsigned int)v5);
LABEL_12:
        v12 = *(_QWORD *)(v3 + 48);
        v13 = (unsigned int)(v11 << 16);
        *(_WORD *)(v3 + 96) = v11;
        if ( v12 && (v14 = *(_DWORD **)(v12 + 8)) != nullptr )
        {
          if ( *(v14 - 1) != -1008624849 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))v14)(v3, 0, (unsigned int)v5, v13);
          v15 = *(_DWORD ***)(v3 + 48);
          if ( !v15 )
            goto LABEL_16;
        }
        else
        {
          writel_relaxed_0(v13, (unsigned int *)(*(_QWORD *)(v3 + 8) + v5));
          v15 = *(_DWORD ***)(v3 + 48);
          if ( !v15 )
            goto LABEL_16;
        }
        v16 = *v15;
        if ( v16 )
        {
          if ( *(v16 - 1) != 616069899 )
            __break(0x8228u);
          result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v16)(v3, 0, (unsigned int)v5);
          goto LABEL_17;
        }
LABEL_16:
        result = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v3 + 8) + v5));
LABEL_17:
        *(_WORD *)(v3 + 98) = WORD1(result);
        return result;
      }
LABEL_11:
      v11 = readl_relaxed_0((unsigned int *)(*(_QWORD *)(v3 + 8) + v5));
      goto LABEL_12;
    }
  }
  return result;
}
