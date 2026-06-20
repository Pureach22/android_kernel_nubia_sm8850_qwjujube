__int64 __fastcall dsi_display_aspace_cb_locked_0(__int64 a1, char a2)
{
  __int64 v4; // x0
  unsigned int iova; // w0
  unsigned __int64 vaddr; // x0

  if ( !a1 )
    return drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: aspace cb called with invalid cb_data\n");
  mutex_lock(*(_QWORD *)(a1 + 264) + 1040LL);
  if ( (a2 & 1) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 1224);
    *(_QWORD *)(a1 + 1240) = 0;
    msm_gem_put_vaddr(v4);
    msm_gem_vunmap(*(_QWORD *)(a1 + 1224), 0);
    goto LABEL_4;
  }
  iova = msm_gem_get_iova(*(_QWORD *)(a1 + 1224), *(_QWORD *)(a1 + 1256), a1 + 1240);
  if ( iova )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get the iova rc %d\n", iova);
  }
  else
  {
    vaddr = msm_gem_get_vaddr(*(_QWORD *)(a1 + 1224));
    *(_QWORD *)(a1 + 1248) = vaddr;
    if ( vaddr && vaddr < 0xFFFFFFFFFFFFF001LL )
    {
LABEL_4:
      if ( *(_DWORD *)(a1 + 160) )
      {
        *(_DWORD *)(*(_QWORD *)(a1 + 168) + 2776LL) = *(_DWORD *)(a1 + 1232);
        *(_DWORD *)(*(_QWORD *)(a1 + 168) + 2780LL) = *(_QWORD *)(a1 + 1240);
        *(_QWORD *)(*(_QWORD *)(a1 + 168) + 2792LL) = *(_QWORD *)(a1 + 1248);
        *(_BYTE *)(*(_QWORD *)(a1 + 168) + 2800LL) = a2 & 1;
        if ( *(_DWORD *)(a1 + 160) >= 2u )
        {
          *(_DWORD *)(*(_QWORD *)(a1 + 216) + 2776LL) = *(_DWORD *)(a1 + 1232);
          *(_DWORD *)(*(_QWORD *)(a1 + 216) + 2780LL) = *(_QWORD *)(a1 + 1240);
          *(_QWORD *)(*(_QWORD *)(a1 + 216) + 2792LL) = *(_QWORD *)(a1 + 1248);
          *(_BYTE *)(*(_QWORD *)(a1 + 216) + 2800LL) = a2 & 1;
        }
      }
      return mutex_unlock(*(_QWORD *)(a1 + 264) + 1040LL);
    }
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get va rc %d\n", 0);
  }
  return mutex_unlock(*(_QWORD *)(a1 + 264) + 1040LL);
}
