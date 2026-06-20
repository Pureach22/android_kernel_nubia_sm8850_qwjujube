__int64 __fastcall msm_audio_ion_free(const void *a1, __int64 a2)
{
  __int64 v4; // x21
  _QWORD *v5; // x9
  unsigned int v6; // w0
  unsigned int v8; // w20

  if ( a1 )
  {
    mutex_lock(a2 + 40);
    if ( *(_BYTE *)a2 == 1 )
    {
      v4 = *(_QWORD *)(a2 + 8);
      v5 = (_QWORD *)(a2 + 24);
      do
      {
        v5 = (_QWORD *)*v5;
        if ( v5 == (_QWORD *)(a2 + 24) )
          goto LABEL_11;
      }
      while ( (const void *)*(v5 - 3) != a1 );
      if ( !*(v5 - 4) )
      {
LABEL_11:
        dev_err(*(_QWORD *)(a2 + 8), "%s: cannot find allocation for dma_buf %pK", "msm_audio_ion_unmap_kernel", a1);
        v8 = -2;
        goto LABEL_13;
      }
      dma_buf_vunmap_unlocked(a1);
      v6 = dma_buf_end_cpu_access(a1, 0);
      if ( !v6 )
        goto LABEL_8;
      v8 = v6;
      dev_err(v4, "%s: kmap dma_buf_end_cpu_access fail\n", "msm_audio_ion_unmap_kernel");
LABEL_13:
      mutex_unlock(a2 + 40);
      return v8;
    }
    else
    {
LABEL_8:
      msm_audio_dma_buf_unmap(a1, a2);
      mutex_unlock(a2 + 40);
      return 0;
    }
  }
  else
  {
    printk(&unk_7B3D, "msm_audio_ion_free");
    return 4294967274LL;
  }
}
