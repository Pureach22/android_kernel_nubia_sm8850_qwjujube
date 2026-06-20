__int64 __fastcall qcom_scmi_get_param(__int64 a1, void *a2, __int64 a3, int a4, size_t a5, size_t a6)
{
  __int64 result; // x0
  __int64 v8; // x8
  _DWORD *v9; // x8
  _DWORD *v15; // x8
  __int64 v16; // x1
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  unsigned int v18; // w0
  __int64 v19; // x1
  unsigned int v20; // w21
  size_t v21; // x2
  __int64 v22; // x22
  void (__fastcall *v23)(__int64, __int64); // x8
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    result = 4294967274LL;
    if ( a2 )
    {
      v8 = *(_QWORD *)(a1 + 8);
      if ( v8 )
      {
        v9 = *(_DWORD **)(v8 + 8);
        v24[0] = 0;
        if ( *(v9 - 1) != -1773214717 )
          __break(0x8228u);
        result = ((__int64 (__fastcall *)(__int64, __int64, size_t, __int64, _QWORD *))v9)(a1, 17, a5 + 16, 128, v24);
        if ( !(_DWORD)result )
        {
          v15 = *(__int64 (__fastcall **)())((char *)&off_18 + v24[0]);
          *v15 = 0;
          v15[1] = a3;
          *(_DWORD *)((char *)&off_8 + (_QWORD)v15) = HIDWORD(a3);
          *(_DWORD *)((char *)&off_8 + (_QWORD)v15 + 4) = a4;
          memcpy(v15 + 4, a2, a5);
          v16 = v24[0];
          v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8) + 24LL);
          if ( *((_DWORD *)v17 - 1) != 1736212784 )
            __break(0x8228u);
          v18 = v17(a1, v16);
          v19 = v24[0];
          if ( v18 )
          {
            v20 = v18;
          }
          else
          {
            v21 = *(_QWORD *)((char *)&unk_30 + v24[0]);
            if ( v21 > a6 )
            {
              printk(&unk_6738, *(_QWORD *)((char *)&unk_30 + v24[0]), a6);
              result = 4294967206LL;
              goto LABEL_17;
            }
            v22 = v24[0];
            v20 = 0;
            memcpy(a2, *(const void **)(v24[0] + 40LL), v21);
            v19 = v22;
          }
          v23 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 8) + 40LL);
          if ( *((_DWORD *)v23 - 1) != -171607853 )
            __break(0x8228u);
          v23(a1, v19);
          result = v20;
        }
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
