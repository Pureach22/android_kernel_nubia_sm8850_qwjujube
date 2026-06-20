unsigned int *__fastcall ipcmem_tx_write(
        unsigned int *result,
        char *src,
        size_t a3,
        unsigned int a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v10; // x21
  __int64 v11; // x25
  size_t v12; // x26
  size_t v15; // x24
  unsigned int v16; // w8
  unsigned int v17; // w10
  unsigned int v18; // w9
  char v19; // w8
  int *v20; // x8
  _DWORD *v21; // x9
  int v22; // w12
  int v23; // w10
  int v24; // w10
  int v25; // w11
  int v26; // w10
  int v27; // w11
  int v28; // w12
  char vars0; // [xsp+0h] [xbp+0h]

  v10 = (__int64)result;
  v11 = **((unsigned int **)result + 2);
  v12 = *result - (unsigned int)v11;
  if ( *result < (unsigned int)v11 )
  {
    __break(0x800u);
    v16 = *result;
  }
  else
  {
    if ( v12 >= a3 )
      v15 = a3;
    else
      v15 = *result - (unsigned int)v11;
    if ( v15 )
      result = (unsigned int *)memcpy((void *)(*((_QWORD *)result + 3) + v11), src, v15);
    if ( v12 < a3 )
      result = (unsigned int *)memcpy(*(void **)(v10 + 24), &src[v15], a3 - v15);
    v16 = *(_DWORD *)v10;
    if ( (unsigned int)(v11 + a3) >= *(_DWORD *)v10 )
      v17 = *(_DWORD *)v10;
    else
      v17 = 0;
    LODWORD(v11) = v11 + a3 - v17;
  }
  __dsb(0xEu);
  v18 = (v11 + 7) & 0xFFFFFFF8;
  if ( v18 < v16 )
    v16 = 0;
  **(_DWORD **)(v10 + 16) = v18 - v16;
  v19 = ipclite_debug_control;
  if ( (ipclite_debug_level & 0x10) != 0 )
  {
    if ( (ipclite_debug_control & 1) == 0 )
    {
      if ( (ipclite_debug_control & 4) == 0 )
        goto LABEL_19;
      goto LABEL_18;
    }
    result = (unsigned int *)printk(&unk_109B9, "ipclite", "ipcmem_tx_write");
    v19 = ipclite_debug_control;
    if ( (ipclite_debug_control & 4) != 0 )
    {
LABEL_18:
      result = (unsigned int *)ipclite_inmem_log(
                                 "APPS:%s:head : %d core_id : %d signal_id : %d\n",
                                 (__int64)"LOW",
                                 **(unsigned int **)(v10 + 16),
                                 a4,
                                 a5,
                                 a6,
                                 a7,
                                 a8,
                                 vars0);
      v19 = ipclite_debug_control;
    }
  }
LABEL_19:
  if ( (v19 & 2) != 0 )
  {
    if ( (debug_status & 1) != 0 )
    {
      if ( a4 >= 9 )
      {
        __break(0x5512u);
        return (unsigned int *)ipclite_intr(result, 0x805F000000000000LL);
      }
      else
      {
        v20 = (int *)ipclite_dbg_struct;
        v21 = (_DWORD *)(ipclite_dbg_struct + 60LL * a4);
        v22 = v21[9];
        v23 = v21[13];
        v21[13] = v21[8];
        v21[14] = v23;
        v24 = v21[15];
        v25 = **(_DWORD **)(v10 + 16);
        v21[15] = v22;
        v21[16] = v24;
        v26 = *v20;
        v21[8] = v25;
        v27 = v21[6];
        v28 = **(_DWORD **)(v10 + 8);
        *v20 = v26 + 1;
        v21[6] = v27 + 1;
        v20[2] = a4;
        v21[9] = v28;
        v20[4] = a5;
      }
    }
    else
    {
      return (unsigned int *)printk(&unk_EEDB, "ipclite", "is_debug_config");
    }
  }
  return result;
}
