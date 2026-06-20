__int64 __fastcall qcom_smd_poll(__int64 a1, __int64 a2, void (__fastcall **a3)(__int64, __int64))
{
  __int64 v3; // x19
  void (__fastcall *v4)(__int64, __int64); // x9
  __int64 v5; // x10
  _DWORD *v6; // x9
  _DWORD *v7; // x10
  __int64 v8; // x10

  v3 = *(_QWORD *)(a1 + 104);
  if ( a3 )
  {
    if ( v3 != -88 )
    {
      v4 = *a3;
      if ( *a3 )
      {
        if ( *((_DWORD *)v4 - 1) != -442429149 )
          __break(0x8229u);
        v4(a2, v3 + 88);
        __dmb(0xBu);
      }
    }
  }
  v5 = *(_QWORD *)(v3 + 72);
  if ( v5 )
  {
    v6 = (_DWORD *)(v5 + 40);
    v7 = (_DWORD *)(v5 + 36);
  }
  else
  {
    v8 = *(_QWORD *)(v3 + 64);
    v6 = (_DWORD *)(v8 + 16);
    v7 = (_DWORD *)(v8 + 12);
  }
  if ( ((*v6 - *v7) | (unsigned int)-*(_DWORD *)(v3 + 128)) >= 0xFFFFFFEB )
    return 0;
  else
    return 260;
}
