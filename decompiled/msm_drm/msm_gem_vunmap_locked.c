__int64 __fastcall msm_gem_vunmap_locked(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v3; // x8
  __int64 v4; // x8
  __int64 v5; // x8
  _QWORD v6[3]; // [xsp+8h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = *(_QWORD *)(a1 + 432);
  v6[1] = 0;
  if ( (mutex_is_locked(a1 + 544) & 1) != 0 )
  {
    result = *(_QWORD *)(a1 + 432);
    if ( !result )
      goto LABEL_11;
  }
  else
  {
    __break(0x800u);
    result = *(_QWORD *)(a1 + 432);
    if ( !result )
      goto LABEL_11;
  }
  if ( *(_BYTE *)(a1 + 373) )
  {
    __break(0x800u);
  }
  else
  {
    v3 = *(_QWORD **)(a1 + 240);
    if ( v3 )
    {
      result = dma_buf_vunmap_unlocked(*v3, v6);
      v4 = *(_QWORD *)(a1 + 8);
      if ( v4 )
      {
        v5 = *(_QWORD *)(v4 + 8);
        if ( v5 )
        {
          if ( (*(_BYTE *)(v5 + 844) & 0x20) == 0 )
            result = dma_buf_end_cpu_access(**(_QWORD **)(a1 + 240), 0);
        }
      }
    }
    else
    {
      result = vunmap();
    }
    *(_QWORD *)(a1 + 432) = 0;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
