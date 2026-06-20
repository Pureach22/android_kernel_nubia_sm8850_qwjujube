__int64 __fastcall qcom_slim_ngd_get_laddr(__int64 a1, int *a2, _BYTE *a3)
{
  __int64 result; // x0
  int v7; // w9
  __int16 v8; // w10
  unsigned int v9; // w0
  unsigned int v10; // w20
  int v12; // w8
  _QWORD v13[3]; // [xsp+8h] [xbp-68h] BYREF
  _QWORD v14[4]; // [xsp+20h] [xbp-50h] BYREF
  int v15; // [xsp+40h] [xbp-30h]
  unsigned __int16 v16; // [xsp+44h] [xbp-2Ch]
  __int64 v17; // [xsp+48h] [xbp-28h] BYREF
  __int16 v18; // [xsp+50h] [xbp-20h]
  __int64 v19; // [xsp+58h] [xbp-18h] BYREF
  __int16 v20; // [xsp+60h] [xbp-10h]
  __int64 v21; // [xsp+68h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[2] = 0;
  v14[0] = 458752;
  v13[0] = 0xFF000000000D020BLL;
  v13[1] = v14;
  v14[2] = &v19;
  v14[3] = 0;
  v16 = 0;
  v15 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v14[1] = &v17;
  result = slim_alloc_txn_tid(a1, v13);
  if ( (result & 0x80000000) == 0 )
  {
    v7 = *a2;
    v8 = *((_WORD *)a2 + 2);
    LOBYTE(v19) = BYTE6(v13[0]);
    *(_DWORD *)((char *)&v19 + 1) = v7;
    *(_WORD *)((char *)&v19 + 5) = v8;
    v9 = qcom_slim_ngd_xfer_msg_sync(a1, v13);
    if ( v9 )
    {
      v10 = v9;
      slim_free_txn_tid(a1, v13);
      result = v10;
    }
    else if ( (_DWORD)v17 == v15 && WORD2(v17) == v16 )
    {
      result = 4294967290LL;
    }
    else
    {
      *a3 = BYTE6(v17);
      _slimbus_dbg();
      v12 = *(_DWORD *)(a1 + 4548);
      if ( v12 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 4560), "%s end ret : %d\n", "qcom_slim_ngd_get_laddr", 0);
        v12 = *(_DWORD *)(a1 + 4548);
      }
      if ( !v12 )
        ipc_log_string(*(_QWORD *)(a1 + 4568), "%s end ret : %d\n", "qcom_slim_ngd_get_laddr", 0);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
