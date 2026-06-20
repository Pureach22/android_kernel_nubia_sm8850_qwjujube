__int64 __fastcall qcom_slim_ngd_rx_msgq_cb(__int64 result)
{
  unsigned __int8 *v1; // x24
  _QWORD *v2; // x19
  __int64 v3; // x23
  unsigned __int8 v4; // w22
  unsigned __int8 v5; // w21
  int v6; // w20
  int v7; // w8
  int v8; // w22
  int v9; // w25
  _BOOL4 v12; // w8
  __int64 v13; // x0
  __int64 v14; // x20
  __int64 v15; // x20
  __int64 v16; // x21
  _DWORD *v17; // x8
  __int64 v18; // x0
  __int64 (*v19)(void); // x8
  __int64 (*v20)(void); // x8
  _QWORD v21[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v22; // [xsp+18h] [xbp-18h]
  __int64 v23; // [xsp+20h] [xbp-10h]
  __int64 v24; // [xsp+28h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
    goto LABEL_34;
  v1 = *(unsigned __int8 **)(result + 40);
  v2 = (_QWORD *)result;
  v3 = *(_QWORD *)(result + 8);
  v4 = *v1;
  v5 = v1[1];
  v6 = *v1 & 0x1F;
  _slimbus_dbg();
  v7 = *(_DWORD *)(v3 + 5476);
  if ( v7 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(v3 + 5488), "BAM RX len = %d buf[0]:0x%x buf[1]:0x%x\n", v6, *v1, v1[1]);
    v7 = *(_DWORD *)(v3 + 5476);
  }
  if ( !v7 )
    ipc_log_string(*(_QWORD *)(v3 + 5496), "BAM RX len = %d buf[0]:0x%x buf[1]:0x%x\n", v6, *v1, v1[1]);
  v8 = v4 & 0xE0;
  v9 = v5 & 0x7F;
  if ( v8 == 192 && (v5 & 0x7F) == 0 )
    queue_work_on(32, *(_QWORD *)(v3 + 5008), v3 + 4944);
  v12 = (v9 == 14 || v9 == 37) && v8 == 192;
  if ( (v5 & 0x3F) == 0x24 || v12 )
  {
    v13 = slim_msg_response(v3 + 928, v1 + 4, v1[3], (unsigned int)(v6 - 4));
    v14 = *(_QWORD *)(v3 + 928);
    *(_QWORD *)(v14 + 520) = ktime_get_mono_fast_ns(v13);
  }
  v15 = *(_QWORD *)(v3 + 1984);
  v16 = v2[4];
  v22 = 0;
  v23 = 0;
  v21[0] = 0;
  v21[1] = 0;
  sg_init_table(v21, 1);
  v22 = v16;
  LODWORD(v23) = 40;
  if ( !v15 || !*(_QWORD *)v15 || (v17 = *(_DWORD **)(*(_QWORD *)v15 + 272LL)) == nullptr )
  {
    *v2 = 0;
LABEL_33:
    result = dev_err(*(_QWORD *)(v3 + 1968), "Unable to prepare rx channel\n");
    goto LABEL_34;
  }
  if ( *(v17 - 1) != -1221891457 )
    __break(0x8228u);
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64, _QWORD))v17)(v15, v21, 1, 2, 1, 0);
  *v2 = v18;
  if ( !v18 )
    goto LABEL_33;
  *(_QWORD *)(v18 + 40) = qcom_slim_ngd_rx_msgq_cb;
  *(_QWORD *)(*v2 + 56LL) = v2;
  v19 = *(__int64 (**)(void))(*v2 + 24LL);
  if ( *((_DWORD *)v19 - 1) != 1188179853 )
    __break(0x8228u);
  *(_DWORD *)*v2 = v19();
  v20 = *(__int64 (**)(void))(**(_QWORD **)(v3 + 1984) + 360LL);
  if ( *((_DWORD *)v20 - 1) != 905352215 )
    __break(0x8228u);
  result = v20();
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
