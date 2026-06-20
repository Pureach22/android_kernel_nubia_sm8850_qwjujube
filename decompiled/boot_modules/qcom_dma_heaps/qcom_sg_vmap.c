__int64 __fastcall qcom_sg_vmap(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v4; // w8
  __int64 v5; // x9
  unsigned int v6; // w21
  unsigned __int64 v7; // x0
  int v8; // w8

  v2 = *(_QWORD *)(a1 + 112);
  mem_buf_vmperm_pin(*(_QWORD *)(v2 + 120));
  if ( (mem_buf_vmperm_can_vmap(*(_QWORD *)(v2 + 120)) & 1) != 0 )
  {
    mutex_lock(v2 + 24);
    v4 = *(_DWORD *)(v2 + 96);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v2 + 104);
      v6 = 0;
      *(_DWORD *)(v2 + 96) = v4 + 1;
      *(_QWORD *)a2 = v5;
    }
    else
    {
      v7 = qcom_sg_do_vmap(v2);
      v6 = v7;
      if ( v7 >= 0xFFFFFFFFFFFFF001LL )
      {
        mem_buf_vmperm_unpin(*(_QWORD *)(v2 + 120));
LABEL_9:
        mutex_unlock(v2 + 24);
        return v6;
      }
      v8 = *(_DWORD *)(v2 + 96);
      *(_QWORD *)(v2 + 104) = v7;
      *(_DWORD *)(v2 + 96) = v8 + 1;
      *(_QWORD *)a2 = v7;
      v6 = 0;
    }
    *(_BYTE *)(a2 + 8) = 0;
    goto LABEL_9;
  }
  mem_buf_vmperm_unpin(*(_QWORD *)(v2 + 120));
  return (unsigned int)-1;
}
