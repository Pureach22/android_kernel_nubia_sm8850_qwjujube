unsigned __int64 __fastcall qmi_send_message(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        char a4,
        __int16 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int16 v11; // w3
  unsigned __int64 result; // x0
  unsigned __int64 v13; // x20
  __int64 v14; // x1
  __int64 v15; // x2
  int v16; // w21
  _QWORD v17[2]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v18; // [xsp+18h] [xbp-78h] BYREF
  __int64 v19; // [xsp+20h] [xbp-70h]
  __int64 v20; // [xsp+28h] [xbp-68h]
  __int64 v21; // [xsp+30h] [xbp-60h]
  __int64 v22; // [xsp+38h] [xbp-58h]
  __int64 v23; // [xsp+40h] [xbp-50h]
  __int64 v24; // [xsp+48h] [xbp-48h]
  __int64 v25; // [xsp+50h] [xbp-40h]
  __int64 v26; // [xsp+58h] [xbp-38h]
  __int64 v27; // [xsp+60h] [xbp-30h]
  __int64 v28; // [xsp+68h] [xbp-28h]
  __int64 v29; // [xsp+70h] [xbp-20h]
  __int64 v30; // [xsp+78h] [xbp-18h]
  _QWORD v31[2]; // [xsp+80h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_WORD *)(a3 + 8);
  v31[0] = a6;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  result = qmi_encode_message(a4, a5, v31, v11, a7, a8);
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v13 = result;
    v17[0] = result;
    v17[1] = v31[0];
    if ( a2 )
    {
      v18 = a2;
      LODWORD(v19) = 12;
    }
    mutex_lock(a1 + 1);
    if ( *a1 )
    {
      v16 = kernel_sendmsg(*a1, &v18, v17, 1, v31[0]);
      if ( v16 < 0 )
        printk(&unk_8391, v14, v15);
    }
    else
    {
      v16 = -32;
    }
    mutex_unlock(a1 + 1);
    kfree(v13);
    result = v16 & (v16 >> 31);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
