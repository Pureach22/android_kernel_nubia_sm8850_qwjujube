__int64 __fastcall hfi_adapter_release_cmd_buf(__int64 a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x9
  __int64 v4; // x20
  _QWORD *v5; // x27
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x8
  _QWORD *v9; // x23
  _QWORD *v10; // x26
  _QWORD *v11; // x8
  _QWORD *v12; // x9
  unsigned int v13; // w20
  __int64 v14; // x8
  _QWORD v16[11]; // [xsp+8h] [xbp-58h] BYREF

  v16[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 136) + 120LL);
  memset(v16, 0, 80);
  mutex_lock(v2 + 368);
  v3 = *(_QWORD **)(a1 + 128);
  if ( v3 == (_QWORD *)(a1 + 120) )
  {
    LODWORD(v4) = 0;
  }
  else
  {
    v4 = 0;
    do
    {
      v5 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v5 == v3 && (v6 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      if ( v4 == 10 )
      {
LABEL_35:
        __break(0x5512u);
        __break(1u);
      }
      v16[v4] = v3 - 5;
      v7 = v3[5];
      if ( v7 )
      {
        if ( v3 == (_QWORD *)&unk_68 )
        {
          printk(&unk_245CB0, "_hfi_clear_buffer");
        }
        else
        {
          *((_DWORD *)v3 - 14) = 0;
          *(v3 - 6) = 0;
          *(_DWORD *)(v7 + 64) = 1;
          *((_DWORD *)v3 + 12) = 0;
        }
        *(_DWORD *)(*(_QWORD *)(a1 + 144) + 64LL) = 1;
      }
      ++v4;
      v3 = v5;
    }
    while ( v5 != (_QWORD *)(a1 + 120) );
  }
  v8 = *(_QWORD *)(a1 + 136);
  v9 = *(_QWORD **)(v8 + 64);
  if ( v9 != (_QWORD *)(v8 + 64) )
  {
    do
    {
      v10 = (_QWORD *)*v9;
      if ( v9 - 13 == (_QWORD *)a1 )
      {
        printk(&unk_25A491, "hfi_adapter_release_cmd_buf");
        v11 = (_QWORD *)v9[1];
        if ( (_QWORD *)*v11 == v9 && (v12 = (_QWORD *)*v9, *(_QWORD **)(*v9 + 8LL) == v9) )
        {
          v12[1] = v11;
          *v11 = v12;
        }
        else
        {
          _list_del_entry_valid_or_report(v9);
        }
        *v9 = 0xDEAD000000000100LL;
        v9[1] = 0xDEAD000000000122LL;
        if ( (unsigned int)v4 > 9 )
          goto LABEL_35;
        v8 = *(_QWORD *)(a1 + 136);
        v16[(unsigned int)v4] = v9 - 5;
        LODWORD(v4) = v4 + 1;
      }
      v9 = v10;
    }
    while ( v10 != (_QWORD *)(v8 + 64) );
  }
  if ( !(_DWORD)v4 )
  {
    LODWORD(v4) = 1;
    v16[0] = a1 + 64;
  }
  v13 = hfi_core_release_rx_buffer(*(_QWORD *)(*(_QWORD *)(v8 + 120) + 32LL), v16, (unsigned int)v4);
  if ( v13 )
  {
    printk(&unk_26874C, "hfi_adapter_release_cmd_buf");
  }
  else
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 144) + 64LL) = 1;
    if ( a1 )
    {
      v14 = *(_QWORD *)(a1 + 144);
      if ( v14 )
      {
        *(_DWORD *)(a1 + 48) = 0;
        *(_QWORD *)(a1 + 56) = 0;
        *(_DWORD *)(v14 + 64) = 1;
        *(_DWORD *)(a1 + 152) = 0;
      }
      else
      {
        printk(&unk_2686DF, "_hfi_clear_buffer");
      }
    }
    else
    {
      printk(&unk_245CB0, "_hfi_clear_buffer");
    }
  }
  mutex_unlock(*(_QWORD *)(*(_QWORD *)(a1 + 136) + 120LL) + 368LL);
  _ReadStatusReg(SP_EL0);
  return v13;
}
