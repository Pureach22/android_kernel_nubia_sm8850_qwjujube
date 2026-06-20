__int64 __fastcall venus_hfi_set_crc(__int64 a1)
{
  int v2; // w3
  __int64 v3; // x0
  unsigned int v4; // w1
  __int64 result; // x0
  int v6; // w6
  unsigned int *v7; // x0
  unsigned int v8; // w1
  int v9; // w9
  __int64 v10; // x20
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  unsigned int v15; // w19

  v2 = *(_DWORD *)(a1 + 6600);
  v3 = *(_QWORD *)(a1 + 6464);
  v4 = *(_DWORD *)(a1 + 6472);
  *(_DWORD *)(a1 + 6600) = v2 + 1;
  result = hfi_create_header(v3, v4, 0, v2);
  if ( (_DWORD)result )
    goto LABEL_8;
  v6 = *(_DWORD *)(a1 + 6604);
  v7 = *(unsigned int **)(a1 + 6464);
  v8 = *(_DWORD *)(a1 + 6472);
  v9 = *(_BYTE *)(a1 + 6444) ? 8 : 0;
  *(_DWORD *)(a1 + 6448) = *(_DWORD *)(a1 + 6448) & 0xFFFFFFF7 | v9;
  *(_DWORD *)(a1 + 6604) = v6 + 1;
  result = hfi_create_packet(v7, v8, 50331658, 0, 9, 0, v6, (const void *)(a1 + 6448), 4u);
  if ( (_DWORD)result
    || (v10 = *(_QWORD *)(a1 + 6464), result = _resume(a1), (_DWORD)result)
    || (result = venus_hfi_queue_cmd_write(a1, v10), (_DWORD)result) )
  {
LABEL_8:
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v15 = result;
      printk(&unk_8F66F, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_set_crc");
      return v15;
    }
  }
  else
  {
    _schedule_power_collapse_work(a1, v11, v12, v13, v14);
    return 0;
  }
  return result;
}
