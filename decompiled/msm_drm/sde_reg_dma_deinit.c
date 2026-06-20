void *__fastcall sde_reg_dma_deinit(void *result)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  int v3; // w8

  if ( (unsigned int)result >= 2 )
    return (void *)_drm_err("invalid dpu idx %d\n", (_DWORD)result);
  v1 = (_QWORD *)((char *)&reg_dma + 176 * (unsigned int)result);
  if ( *v1 )
  {
    v2 = v1[2];
    if ( v2 )
    {
      v3 = *(_DWORD *)(v2 + 24);
      if ( (unsigned int)(v3 - 0x10000) < 3 || v3 == 0x20000 )
        ((void (__fastcall *)(_QWORD))deinit_v1)((unsigned int)result);
      v1[20] = 0;
      v1[21] = 0;
      v1[18] = 0;
      v1[19] = 0;
      v1[16] = 0;
      v1[17] = 0;
      v1[14] = 0;
      v1[15] = 0;
      v1[12] = 0;
      v1[13] = 0;
      v1[10] = 0;
      v1[11] = 0;
      v1[8] = 0;
      v1[9] = 0;
      v1[6] = 0;
      v1[7] = 0;
      v1[4] = 0;
      v1[5] = 0;
      v1[1] = 0;
      v1[2] = 0;
      *v1 = 0;
      v1[3] = 0;
      return memcpy(v1 + 3, set_default_dma_ops_ops, 0x88u);
    }
  }
  return result;
}
