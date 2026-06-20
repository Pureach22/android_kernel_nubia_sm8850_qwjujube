__int64 __fastcall extract_scaling_params_service_ready_ext_tlv(__int64 a1, __int64 a2, unsigned __int8 a3, _DWORD *a4)
{
  _DWORD *v4; // x20
  __int64 (*v6)(void); // x8

  if ( !a2 )
    return 4;
  v4 = (_DWORD *)(*(_QWORD *)(a2 + 176) + 28LL * a3);
  v6 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3712LL);
  if ( *((_DWORD *)v6 - 1) != -2112860426 )
    __break(0x8228u);
  *a4 = v6();
  a4[2] = v4[3];
  a4[1] = v4[2];
  a4[3] = v4[4];
  a4[4] = v4[5];
  a4[5] = v4[6];
  return 0;
}
