__int64 __fastcall qmi_send_new_lookup(__int64 a1, int *a2)
{
  int v3; // w10
  int v4; // w8
  int v5; // w9
  int v6; // w8
  int v7; // w9
  unsigned int v8; // w0
  __int64 v9; // x2
  __int64 result; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-A0h] BYREF
  _DWORD *v12; // [xsp+10h] [xbp-90h] BYREF
  int v13; // [xsp+18h] [xbp-88h]
  int v14; // [xsp+1Ch] [xbp-84h]
  __int64 v15; // [xsp+20h] [xbp-80h]
  __int64 v16; // [xsp+28h] [xbp-78h]
  __int64 v17; // [xsp+30h] [xbp-70h]
  __int64 v18; // [xsp+38h] [xbp-68h]
  __int64 v19; // [xsp+40h] [xbp-60h]
  __int64 v20; // [xsp+48h] [xbp-58h]
  __int64 v21; // [xsp+50h] [xbp-50h]
  __int64 v22; // [xsp+58h] [xbp-48h]
  __int64 v23; // [xsp+60h] [xbp-40h]
  __int64 v24; // [xsp+68h] [xbp-38h]
  __int64 v25; // [xsp+70h] [xbp-30h]
  _DWORD v26[3]; // [xsp+78h] [xbp-28h] BYREF
  _DWORD v27[3]; // [xsp+84h] [xbp-1Ch] BYREF
  __int64 v28; // [xsp+90h] [xbp-10h]
  __int64 v29; // [xsp+98h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = v27;
  v11[1] = 20;
  v3 = *a2;
  v4 = a2[1];
  v5 = a2[2];
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v6 = v4 | (v5 << 8);
  v7 = *(_DWORD *)(a1 + 60);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v27[2] = v6;
  LOWORD(v6) = *(_WORD *)(a1 + 56);
  v26[1] = v7;
  v26[0] = (unsigned __int16)v6;
  v26[2] = -2;
  v12 = v26;
  v14 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v28 = 0;
  v27[0] = 10;
  v27[1] = v3;
  v13 = 12;
  mutex_lock(a1 + 8);
  if ( *(_QWORD *)a1 )
  {
    v8 = kernel_sendmsg(*(_QWORD *)a1, &v12, v11, 1, 20);
    if ( (v8 & 0x80000000) != 0 )
      printk(&unk_835E, v8, v9);
  }
  result = mutex_unlock(a1 + 8);
  _ReadStatusReg(SP_EL0);
  return result;
}
