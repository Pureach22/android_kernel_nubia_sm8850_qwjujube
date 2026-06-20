__int64 __fastcall msm_audio_ion_ioctl(__int64 a1, int a2, unsigned int a3)
{
  __int64 v4; // x28
  __int64 *v5; // x8
  const void *v6; // x20
  __int64 *v7; // x8
  __int64 v8; // x20
  __int64 v9; // x21
  int v10; // w24
  __int64 *v11; // x8
  __int64 v12; // x21
  __int64 v13; // x20
  unsigned __int64 v14; // x0
  __int64 *v15; // x23
  char v16; // w27
  __int64 v17; // x24
  __int64 v18; // x25
  __int64 *v19; // x0
  _QWORD *v20; // x26
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x0
  __int64 v23; // x27
  _QWORD *v24; // x0
  __int64 v25; // x2
  _QWORD *v26; // x1
  __int64 *v27; // x8
  __int64 v28; // x20
  __int64 v29; // x21
  __int64 *v30; // x8
  __int64 result; // x0
  void *v32; // x0
  int v33; // w3
  __int64 v34; // x0
  int v35; // w3
  __int64 v36; // x0
  _QWORD *v37; // x9
  __int64 *v38; // x9
  __int64 v39; // x0
  __int64 *v40; // x1
  char v41; // [xsp+4h] [xbp-3Ch]
  __int64 v42; // [xsp+8h] [xbp-38h]
  __int64 v43; // [xsp+10h] [xbp-30h] BYREF
  __int64 v44; // [xsp+18h] [xbp-28h] BYREF
  __int64 v45; // [xsp+20h] [xbp-20h] BYREF
  _QWORD v46[3]; // [xsp+28h] [xbp-18h] BYREF

  v46[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v44 = 8;
  v46[0] = 0x600000016LL;
  v46[1] = 0x600000025LL;
  v43 = 0x2000400000LL;
  v45 = 0x700000003LL;
  if ( a2 > 1074028908 )
  {
    if ( a2 == 1074028909 )
    {
      mutex_lock(&msm_audio_ion_fd_list);
      v27 = &qword_7690;
      while ( 1 )
      {
        v27 = (__int64 *)*v27;
        if ( v27 == &qword_7690 )
          break;
        if ( *((_DWORD *)v27 - 12) == a3 )
        {
          v28 = *(v27 - 2);
          v29 = *(v27 - 4);
          mutex_unlock(&msm_audio_ion_fd_list);
          v10 = qcom_scm_assign_mem(v28, v29, &v44, v46, 2);
          if ( v10 < 0 )
          {
            v32 = &unk_7866;
LABEL_50:
            printk(v32, "msm_audio_ion_ioctl");
            goto LABEL_89;
          }
          mutex_lock(&msm_audio_ion_fd_list);
          v30 = &qword_7690;
          while ( 1 )
          {
            v30 = (__int64 *)*v30;
            if ( v30 == &qword_7690 )
              goto LABEL_88;
            if ( *((_DWORD *)v30 - 12) == a3 )
            {
              *((_BYTE *)v30 + 16) = 1;
              goto LABEL_88;
            }
          }
        }
      }
    }
    else
    {
      if ( a2 != 1074028910 )
        goto LABEL_45;
      mutex_lock(&msm_audio_ion_fd_list);
      v7 = &qword_7690;
      while ( 1 )
      {
        v7 = (__int64 *)*v7;
        if ( v7 == &qword_7690 )
          break;
        if ( *((_DWORD *)v7 - 12) == a3 )
        {
          v8 = *(v7 - 2);
          v9 = *(v7 - 4);
          mutex_unlock(&msm_audio_ion_fd_list);
          v10 = qcom_scm_assign_mem(v8, v9, &v43, &v45, 1);
          if ( v10 < 0 )
          {
            v32 = &unk_7A5E;
            goto LABEL_50;
          }
          mutex_lock(&msm_audio_ion_fd_list);
          v11 = &qword_7690;
          while ( 1 )
          {
            v11 = (__int64 *)*v11;
            if ( v11 == &qword_7690 )
              goto LABEL_88;
            if ( *((_DWORD *)v11 - 12) == a3 )
            {
              *((_BYTE *)v11 + 16) = 0;
              goto LABEL_88;
            }
          }
        }
      }
    }
    mutex_unlock(&msm_audio_ion_fd_list);
    printk(&unk_76E1, "msm_audio_ion_ioctl");
    result = -22;
    goto LABEL_90;
  }
  v4 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 656LL);
  if ( a2 == 1074028897 )
  {
    v12 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
    if ( !v12 )
    {
      result = -12;
      goto LABEL_90;
    }
    v13 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 72);
    if ( !v13 )
    {
      kfree(v12);
      result = -12;
      goto LABEL_90;
    }
    if ( (*(_BYTE *)(v4 - 120) & 1) == 0 )
    {
      v10 = -517;
      goto LABEL_74;
    }
    v14 = dma_buf_get(a3);
    if ( !v14 || (v15 = (__int64 *)v14, v14 >= 0xFFFFFFFFFFFFF001LL) )
    {
      printk(&unk_7C57, "msm_audio_ion_import");
      v10 = -22;
      goto LABEL_74;
    }
    v16 = *(_BYTE *)(v4 - 136);
    v17 = *(_QWORD *)(v4 - 128);
    v18 = _kmalloc_cache_noprof(dma_buf_map_attachment_unlocked, 3520, 16);
    if ( v18 )
    {
      v19 = (__int64 *)_kmalloc_cache_noprof(dma_buf_vmap_unlocked, 3520, 56);
      v20 = v19;
      if ( v19 )
      {
        v19[2] = (__int64)v15;
        v42 = *v15;
        *v19 = *v15;
        v21 = dma_buf_attach(v15, v17);
        v20[3] = v21;
        if ( v21 >= 0xFFFFFFFFFFFFF001LL )
        {
          v33 = v21;
          v34 = v17;
          v10 = v33;
          dev_err(v34, "%s: Fail to attach dma_buf to CB, rc = %d\n", "msm_audio_dma_buf_map", v33);
        }
        else
        {
          v22 = dma_buf_map_attachment_unlocked();
          v20[4] = v22;
          if ( v22 < 0xFFFFFFFFFFFFF001LL )
          {
            v41 = v16;
            v23 = *(_QWORD *)(*(_QWORD *)v22 + 16LL);
            kfree(v18);
            mutex_lock(v4 - 96);
            v24 = v20 + 5;
            v25 = v4 - 112;
            v26 = *(_QWORD **)(v4 - 104);
            if ( v20 + 5 == (_QWORD *)(v4 - 112) || v26 == v24 || *v26 != v25 )
            {
              _list_add_valid_or_report(v24, v26, v25);
            }
            else
            {
              *(_QWORD *)(v4 - 104) = v24;
              v20[5] = v25;
              v20[6] = v26;
              *v26 = v24;
            }
            v18 = v42;
            mutex_unlock(v4 - 96);
            if ( (v41 & 1) == 0 )
              goto LABEL_80;
            if ( *(_BYTE *)(v4 - 136) == 1 )
              v23 |= *(_QWORD *)(v4 - 48);
            if ( (unsigned int)dma_buf_begin_cpu_access(v15, 0) )
            {
              printk(&unk_7A34, "msm_audio_ion_map_kernel");
            }
            else
            {
              if ( !(unsigned int)dma_buf_vmap_unlocked(v15, v12) )
              {
                mutex_lock(v4 - 96);
                v37 = (_QWORD *)(v4 - 112);
                while ( 1 )
                {
                  v37 = (_QWORD *)*v37;
                  if ( v37 == (_QWORD *)(v4 - 112) )
                    break;
                  if ( (__int64 *)*(v37 - 3) == v15 )
                  {
                    *(v37 - 4) = v12;
                    break;
                  }
                }
                mutex_unlock(v4 - 96);
                goto LABEL_80;
              }
              printk(&unk_78EC, "msm_audio_ion_map_kernel");
              dma_buf_end_cpu_access(v15, 0);
            }
            printk(&unk_7C71, "msm_audio_ion_buf_map");
            mutex_lock(v4 - 96);
            msm_audio_dma_buf_unmap(v15, v4 - 136);
            mutex_unlock(v4 - 96);
            v10 = -12;
            printk(&unk_7E59, "msm_audio_ion_import");
LABEL_74:
            printk(&unk_7ADE, "msm_audio_ion_ioctl");
            kfree(v12);
            kfree(v13);
            goto LABEL_89;
          }
          v35 = v22;
          v36 = v17;
          v10 = v35;
          dev_err(v36, "%s: Fail to map attachment, rc = %d\n", "msm_audio_dma_buf_map", v35);
          dma_buf_detach(v20[2], v20[3]);
        }
        kfree(v18);
      }
      else
      {
        v42 = 0;
        v10 = -12;
        v20 = (_QWORD *)v18;
      }
      kfree(v20);
      v18 = v42;
      if ( (v16 & 1) == 0 )
      {
LABEL_79:
        v23 = 0;
LABEL_80:
        v10 = 0;
        goto LABEL_81;
      }
    }
    else
    {
      v10 = -12;
      if ( (v16 & 1) == 0 )
        goto LABEL_79;
    }
    printk(&unk_76FF, "msm_audio_ion_get_phys");
    printk(&unk_78BA, "msm_audio_ion_buf_map");
    dma_buf_put(v15);
    printk(&unk_7E59, "msm_audio_ion_import");
    if ( (v10 & 0x80000000) == 0 )
    {
      v23 = 0;
      v15 = nullptr;
LABEL_81:
      *(_DWORD *)v13 = a3;
      *(_QWORD *)(v13 + 24) = v15;
      *(_QWORD *)(v13 + 32) = v23;
      *(_QWORD *)(v13 + 8) = v15;
      *(_QWORD *)(v13 + 16) = v18;
      *(_QWORD *)(v13 + 40) = *(_QWORD *)(v4 - 128);
      mutex_lock(&msm_audio_ion_fd_list);
      v38 = &qword_7690;
      while ( 1 )
      {
        v38 = (__int64 *)*v38;
        if ( v38 == &qword_7690 )
          break;
        if ( *((_DWORD *)v38 - 12) == *(_DWORD *)v13 )
        {
          printk(&unk_7D07, "msm_audio_update_fd_list");
          goto LABEL_88;
        }
      }
      v39 = v13 + 48;
      v40 = (__int64 *)qword_7698;
      if ( qword_7698 == v13 + 48 || *(__int64 **)qword_7698 != &qword_7690 )
      {
        _list_add_valid_or_report(v39, qword_7698, &qword_7690);
      }
      else
      {
        qword_7698 = v13 + 48;
        *(_QWORD *)(v13 + 48) = &qword_7690;
        *(_QWORD *)(v13 + 56) = v40;
        *v40 = v39;
      }
LABEL_88:
      mutex_unlock(&msm_audio_ion_fd_list);
      goto LABEL_89;
    }
    goto LABEL_74;
  }
  if ( a2 != 1074028898 )
  {
LABEL_45:
    printk(&unk_7E2E, "msm_audio_ion_ioctl");
    v10 = -22;
    goto LABEL_89;
  }
  mutex_lock(&msm_audio_ion_fd_list);
  v5 = &qword_7690;
  while ( 1 )
  {
    v5 = (__int64 *)*v5;
    if ( v5 == &qword_7690 )
      break;
    if ( *((_DWORD *)v5 - 12) == a3 )
    {
      v6 = (const void *)*(v5 - 3);
      goto LABEL_42;
    }
  }
  v6 = nullptr;
LABEL_42:
  mutex_unlock(&msm_audio_ion_fd_list);
  v10 = msm_audio_ion_free(v6, v4 - 136);
  if ( (v10 & 0x80000000) == 0 )
  {
    msm_audio_delete_fd_entry((__int64)v6, a3);
LABEL_89:
    result = v10;
    goto LABEL_90;
  }
  printk(&unk_7726, "msm_audio_ion_ioctl");
  if ( v10 != -2 )
    goto LABEL_89;
  msm_audio_delete_fd_entry((__int64)v6, a3);
  result = 0;
LABEL_90:
  _ReadStatusReg(SP_EL0);
  return result;
}
