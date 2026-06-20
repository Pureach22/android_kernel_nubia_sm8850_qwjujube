__int64 __fastcall kgsl_snapshot_add_section(
        __int64 result,
        __int16 a2,
        _QWORD *a3,
        __int64 (__fastcall *a4)(__int64, __int64, unsigned __int64, __int64),
        __int64 a5)
{
  unsigned __int64 v5; // x8
  bool v6; // cf
  unsigned __int64 v7; // x8
  __int64 v8; // x19
  __int16 v9; // w20
  _QWORD *v10; // x21
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x8
  __int64 v14; // x9

  v5 = a3[12];
  v6 = v5 >= 8;
  v7 = v5 - 8;
  if ( !v6 )
    return result;
  v8 = a3[11];
  if ( !a4 )
  {
    result = 0;
LABEL_9:
    v11 = (unsigned int)(result + 8);
    *(_WORD *)(v8 + 2) = a2;
    *(_WORD *)v8 = -21555;
    *(_DWORD *)(v8 + 4) = v11;
    v12 = a3[10];
    v13 = a3[11] + v11;
    v14 = a3[12];
    a3[11] = v13;
    a3[12] = v14 - *(unsigned int *)(v8 + 4);
    a3[10] = v12 + *(unsigned int *)(v8 + 4);
    return result;
  }
  v9 = a2;
  v10 = a3;
  if ( *((_DWORD *)a4 - 1) != -345416796 )
    __break(0x8228u);
  result = a4(result, v8 + 8, v7, a5);
  a2 = v9;
  a3 = v10;
  if ( result )
    goto LABEL_9;
  return result;
}
