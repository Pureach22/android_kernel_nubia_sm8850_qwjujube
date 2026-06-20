__int64 __fastcall iris_hfi_get_fw_info(__int64 a1, __int64 a2)
{
  __int64 v4; // x3
  unsigned __int64 v5; // x9
  _QWORD *v6; // x8
  unsigned __int64 v7; // x10
  __int64 result; // x0
  unsigned __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x11
  __int64 v13; // x12
  __int64 v14; // x9
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x12
  __int64 v20; // x9
  __int64 v21; // x10
  __int64 v22; // x8
  __int64 v23; // x11
  unsigned __int64 StatusReg; // x8

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 80);
    v5 = 0;
    v6 = (_QWORD *)(cvp_driver + 136);
    do
    {
      v7 = v5 + 1;
      if ( v5 > 0x7E )
        break;
    }
    while ( *((_BYTE *)v6 + v5++) != 86 );
    if ( v7 == 127 )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8B253, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      }
      *(_BYTE *)a2 = 0;
    }
    else
    {
      v11 = *(_QWORD *)(cvp_driver + 160);
      v12 = *v6;
      v13 = *(_QWORD *)(cvp_driver + 144);
      *(_QWORD *)(a2 + 16) = *(_QWORD *)(cvp_driver + 152);
      *(_QWORD *)(a2 + 24) = v11;
      *(_QWORD *)a2 = v12;
      *(_QWORD *)(a2 + 8) = v13;
      v14 = v6[7];
      v15 = v6[4];
      v16 = v6[5];
      *(_QWORD *)(a2 + 48) = v6[6];
      *(_QWORD *)(a2 + 56) = v14;
      *(_QWORD *)(a2 + 32) = v15;
      *(_QWORD *)(a2 + 40) = v16;
      v17 = v6[11];
      v18 = v6[8];
      v19 = v6[9];
      *(_QWORD *)(a2 + 80) = v6[10];
      *(_QWORD *)(a2 + 88) = v17;
      *(_QWORD *)(a2 + 64) = v18;
      *(_QWORD *)(a2 + 72) = v19;
      v21 = v6[14];
      v20 = v6[15];
      v23 = v6[12];
      v22 = v6[13];
      *(_QWORD *)(a2 + 112) = v21;
      *(_QWORD *)(a2 + 120) = v20;
      *(_QWORD *)(a2 + 96) = v23;
      *(_QWORD *)(a2 + 104) = v22;
      *(_BYTE *)(a2 + 127) = 0;
    }
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      printk(&unk_9641D, "core", a2, v4);
    *(_QWORD *)(a2 + 128) = *(_QWORD *)(*(_QWORD *)(a1 + 2168) + 8LL);
    *(_DWORD *)(a2 + 136) = *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 8LL);
    *(_DWORD *)(a2 + 140) = *(_DWORD *)(*(_QWORD *)(a1 + 2168) + 40LL);
    *(_DWORD *)(a2 + 144) = **(_DWORD **)(a1 + 2168);
    mutex_unlock(a1 + 80);
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_8DBDA, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
