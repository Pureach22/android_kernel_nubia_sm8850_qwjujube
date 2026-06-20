__int64 __fastcall qcom_scmi_stop_activity(__int64 a1, const void *a2, __int64 a3, int a4, size_t a5)
{
  __int64 v5; // x8
  __int64 (*v6)(void); // x8
  __int64 result; // x0
  __int64 (__fastcall *v13)(); // x8
  _DWORD *v14; // x8
  unsigned int v15; // w20
  _DWORD *v16; // x8

  _ReadStatusReg(SP_EL0);
  if ( a1 && (v5 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    v6 = *(__int64 (**)(void))(v5 + 8);
    if ( *((_DWORD *)v6 - 1) != -1773214717 )
      __break(0x8228u);
    result = v6();
    if ( !(_DWORD)result )
    {
      v13 = off_18;
      *(_DWORD *)off_18 = 0;
      *((_DWORD *)v13 + 1) = a3;
      *(_DWORD *)((char *)&off_8 + (_QWORD)v13) = HIDWORD(a3);
      *(_DWORD *)((char *)&off_8 + (_QWORD)v13 + 4) = a4;
      memcpy((char *)v13 + 16, a2, a5);
      v14 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 24LL);
      if ( *(v14 - 1) != 1736212784 )
        __break(0x8228u);
      v15 = ((__int64 (__fastcall *)(__int64, _QWORD))v14)(a1, 0);
      v16 = *(_DWORD **)(*(_QWORD *)(a1 + 8) + 40LL);
      if ( *(v16 - 1) != -171607853 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v16)(a1, 0);
      result = v15;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
