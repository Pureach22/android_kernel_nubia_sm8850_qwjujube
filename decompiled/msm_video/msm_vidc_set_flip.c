__int64 __fastcall msm_vidc_set_flip(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x9
  bool v3; // zf
  unsigned __int64 v4; // x9
  char v5; // w10
  int v6; // w12
  int v7; // w11
  int v8; // w8
  unsigned int v9; // w20
  __int64 v10; // x19
  int v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w8
  _DWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 22832);
  v3 = v2 == 0;
  v4 = *(unsigned int *)(a1 + 23000) | v2;
  v5 = *(_BYTE *)(*(_QWORD *)(a1 + 1848) + 320LL);
  v6 = !v3;
  if ( v3 )
    v7 = 2;
  else
    v7 = 3;
  if ( *(_DWORD *)(a1 + 23000) )
    v8 = v7;
  else
    v8 = v6;
  v15[0] = v8;
  if ( (v5 & 1) == 0 || !v4 )
    goto LABEL_16;
  v9 = a2;
  v10 = a1;
  v11 = *(_DWORD *)(a1 + 23672) ? 2 : 1;
  v15[1] = v11;
  v12 = ((__int64 (__fastcall *)(__int64, __int64))msm_vidc_packetize_control)(a1, 118);
  a2 = v9;
  v13 = v12;
  a1 = v10;
  if ( !v13 )
LABEL_16:
    v13 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _DWORD *, __int64, const char *))msm_vidc_packetize_control)(
            a1,
            a2,
            9,
            v15,
            4,
            "msm_vidc_set_flip");
  _ReadStatusReg(SP_EL0);
  return v13;
}
