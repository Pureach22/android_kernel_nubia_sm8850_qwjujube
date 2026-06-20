__int64 __fastcall qrtr_print_wakeup_reason(unsigned __int8 *a1)
{
  int v2; // w8
  unsigned int v3; // w20
  unsigned int v4; // w21
  unsigned int v5; // w22
  unsigned int v6; // w23
  __int64 v7; // x8
  __int64 v8; // x25
  unsigned int v9; // w26
  int service_id; // w24
  size_t v11; // x2
  __int64 result; // x0
  _QWORD dest[2]; // [xsp+10h] [xbp-10h] BYREF

  dest[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  dest[0] = 0;
  if ( v2 == 3 )
  {
    v3 = *((unsigned __int16 *)a1 + 4);
    v5 = *((unsigned __int16 *)a1 + 6);
    if ( *((unsigned __int16 *)a1 + 5) == 65534 )
      v4 = -2;
    else
      v4 = *((unsigned __int16 *)a1 + 5);
    v8 = a1[3] + 16LL;
    if ( *((unsigned __int16 *)a1 + 7) == 65534 )
      v6 = -2;
    else
      v6 = *((unsigned __int16 *)a1 + 7);
    v7 = 4;
    goto LABEL_11;
  }
  if ( v2 == 1 )
  {
    v3 = *((_DWORD *)a1 + 2);
    v4 = *((_DWORD *)a1 + 3);
    v5 = *((_DWORD *)a1 + 6);
    v6 = *((_DWORD *)a1 + 7);
    v7 = 20;
    v8 = 32;
LABEL_11:
    v9 = *(_DWORD *)&a1[v7];
    goto LABEL_13;
  }
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v3 = 0;
  v9 = 0;
  v8 = 0;
LABEL_13:
  service_id = qrtr_get_service_id(v3, v4);
  if ( service_id < 0 )
    service_id = qrtr_get_service_id(v5, v6);
  if ( v9 >= 8 )
    v11 = 8;
  else
    v11 = v9;
  memcpy(dest, &a1[v8], v11);
  result = printk(&unk_DE8E, "qrtr_print_wakeup_reason", v3, v4, v5, v6, LODWORD(dest[0]), HIDWORD(dest[0]), service_id);
  _ReadStatusReg(SP_EL0);
  return result;
}
