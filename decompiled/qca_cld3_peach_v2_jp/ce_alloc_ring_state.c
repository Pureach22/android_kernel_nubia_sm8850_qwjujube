__int64 __fastcall ce_alloc_ring_state(__int64 *a1, unsigned int a2, int a3)
{
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x19
  __int64 (__fastcall *v9)(_QWORD); // x8
  int v10; // w0
  int v11; // w22
  int v12; // w23
  unsigned int v13; // w8
  __int64 v14; // x21
  __int64 v15; // x0
  __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x9
  __int64 v20; // x0
  __int64 v21; // x8
  _QWORD v22[2]; // [xsp+0h] [xbp-10h] BYREF

  v22[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v22[0] = 0;
  v7 = _qdf_mem_malloc((unsigned int)(8 * a3 + 136), "ce_alloc_ring_state", 2213);
  v8 = v7;
  if ( !v7 )
    goto LABEL_15;
  *(_DWORD *)(v7 + 72) = 0;
  *(_DWORD *)(v7 + 76) = a3;
  *(_DWORD *)v7 = a3;
  *(_DWORD *)(v7 + 4) = a3 - 1;
  *(_QWORD *)(v7 + 88) = v7 + 136;
  *(_DWORD *)(v7 + 96) = (unsigned __int8)a2 + 8;
  v9 = **(__int64 (__fastcall ***)(_QWORD))(v6 + 30696);
  if ( *((_DWORD *)v9 - 1) != -2597194 )
    __break(0x8228u);
  v10 = v9(a2);
  v11 = *((_DWORD *)a1 + 2);
  v12 = v10;
  if ( v11 == 5 )
  {
    v13 = *(_DWORD *)(hif_get_target_info_handle(v6) + 4);
    if ( v13 > 0x2B || ((1LL << v13) & 0xFBFFFB00000LL) == 0 )
    {
      v20 = *(_QWORD *)(v6 + 3936);
      if ( v20 )
      {
        LODWORD(v14) = v12 * a3 + 8;
      }
      else
      {
        LODWORD(v14) = v12 * a3 + 8;
        v20 = qdf_mem_shared_mem_alloc(*(_QWORD *)(v6 + 576), (unsigned int)v14);
        *(_QWORD *)(v6 + 3936) = v20;
        if ( !v20 )
        {
          qdf_trace_msg(61, 2, "%s: Failed to allocate memory for IPA ce ring", "ce_alloc_desc_ring");
          goto LABEL_12;
        }
      }
      if ( *(_BYTE *)(*(_QWORD *)(v6 + 576) + 608LL) )
        v21 = 8;
      else
        v21 = 0;
      v16 = *(_QWORD *)(v20 + v21);
      v15 = *(_QWORD *)(v20 + 32);
      v22[0] = v16;
      *(_QWORD *)(v8 + 24) = v15;
      goto LABEL_9;
    }
  }
  v14 = (unsigned int)(v12 * a3 + 8);
  v15 = hif_mem_alloc_consistent_unaligned(v6, v14, v22, *(unsigned int *)(v8 + 96), v8 + 100);
  *(_QWORD *)(v8 + 24) = v15;
  if ( !v15 )
  {
    qdf_trace_msg(61, 2, "%s: Failed to allocate DMA memory for ce ring id: %u", "ce_alloc_desc_ring", v11);
LABEL_12:
    qdf_trace_msg(61, 2, "%s: ring has no DMA mem", "ce_alloc_ring_state");
    _qdf_mem_free(v8);
    v8 = 0;
    goto LABEL_15;
  }
  v16 = v22[0];
LABEL_9:
  *(_QWORD *)(v8 + 32) = v16;
  qdf_mem_set(v15, (unsigned int)v14, 0);
  v17 = *(_QWORD *)(v8 + 32);
  if ( (v17 & 7) != 0 )
  {
    v17 = (v17 + 7) & 0xFFFFFFFFFFFFFFF8LL;
    v18 = (*(_QWORD *)(v8 + 24) + 7LL) & 0xFFFFFFFFFFFFFFF8LL;
  }
  else
  {
    v18 = *(_QWORD *)(v8 + 24);
  }
  *(_QWORD *)(v8 + 40) = v18;
  *(_QWORD *)(v8 + 48) = v17;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v8;
}
