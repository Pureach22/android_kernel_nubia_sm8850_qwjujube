__int64 __fastcall venus_hfi_trigger_ssr(__int64 a1, int a2, int a3, int a4)
{
  __int64 result; // x0
  int v9; // w3
  __int64 v10; // x0
  unsigned int v11; // w1
  int v12; // w6
  unsigned int *v13; // x0
  unsigned int v14; // w1
  __int64 v15; // x20
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  unsigned int v20; // w19
  _DWORD v21[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 4768) & 1) != 0 )
  {
    result = 0;
  }
  else
  {
    result = _resume(a1);
    if ( !(_DWORD)result )
    {
      v9 = *(_DWORD *)(a1 + 6600);
      v10 = *(_QWORD *)(a1 + 6464);
      v11 = *(_DWORD *)(a1 + 6472);
      v21[0] = a2 | (16 * a3);
      v21[1] = a4;
      *(_DWORD *)(a1 + 6600) = v9 + 1;
      result = hfi_create_header(v10, v11, 0, v9);
      if ( (_DWORD)result )
        goto LABEL_8;
      v12 = *(_DWORD *)(a1 + 6604);
      v13 = *(unsigned int **)(a1 + 6464);
      v14 = *(_DWORD *)(a1 + 6472);
      *(_DWORD *)(a1 + 6604) = v12 + 1;
      result = hfi_create_packet(v13, v14, 16777229, 3, 3, 0, v12, v21, 8u);
      if ( (_DWORD)result
        || (v15 = *(_QWORD *)(a1 + 6464), result = _resume(a1), (_DWORD)result)
        || (result = venus_hfi_queue_cmd_write(a1, v15), (_DWORD)result) )
      {
LABEL_8:
        if ( (msm_vidc_debug & 1) != 0 )
        {
          v20 = result;
          printk(&unk_8F66F, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_trigger_ssr");
          result = v20;
        }
      }
      else
      {
        _schedule_power_collapse_work(a1, v16, v17, v18, v19);
        result = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
