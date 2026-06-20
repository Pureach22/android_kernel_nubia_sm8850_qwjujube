unsigned __int64 __fastcall qmi_send_indication(_QWORD *a1, __int64 a2, __int16 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v12; // w0
  unsigned __int64 v13; // x0
  __int64 v14; // x20
  unsigned __int64 v15; // x19
  __int64 v17; // [xsp+0h] [xbp-50h] BYREF
  __int64 v18; // [xsp+8h] [xbp-48h]
  __int64 v19; // [xsp+10h] [xbp-40h]
  __int64 v20; // [xsp+18h] [xbp-38h]
  __int64 v21; // [xsp+20h] [xbp-30h]
  __int64 v22; // [xsp+28h] [xbp-28h]
  __int64 v23; // [xsp+30h] [xbp-20h]
  __int64 v24; // [xsp+38h] [xbp-18h]
  __int64 v25; // [xsp+40h] [xbp-10h]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v17 = 0;
  v12 = qmi_txn_init((__int64)a1, &v17, 0, 0);
  if ( v12 < 0 )
  {
    v15 = v12;
  }
  else
  {
    v13 = qmi_send_message(a1, a2, (__int64)&v17, 4, a3, a4, a5, a6);
    v14 = v17;
    v15 = v13;
    mutex_lock(v17 + 248);
    idr_remove(v14 + 224, (unsigned __int16)v18);
    mutex_unlock(v14 + 248);
  }
  _ReadStatusReg(SP_EL0);
  return v15;
}
