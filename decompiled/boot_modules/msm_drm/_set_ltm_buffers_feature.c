__int64 __fastcall set_ltm_buffers_feature(__int64 a1, unsigned int **a2, __int64 *a3)
{
  __int64 v3; // x24
  __int64 *v4; // x25
  __int64 v5; // x26
  __int64 result; // x0
  __int64 v9; // x21
  __int64 v11; // x21
  __int64 v12; // x20
  __int64 v13; // x1
  __int64 v14; // x0
  int v15; // w24
  int v16; // w20
  unsigned __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x8
  unsigned __int64 v23; // x1
  int iova; // w0
  __int64 v25; // x8
  unsigned __int64 v26; // x9
  __int64 v27; // x8
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x0
  _QWORD *v33; // x2
  __int64 v34; // x9
  _QWORD *v35; // x10
  __int64 v36; // x8
  _QWORD *v37; // x0
  _QWORD *v38; // x2
  __int64 v39; // x8
  _QWORD *v40; // x0
  _QWORD *v41; // x2
  __int64 v42; // x8
  _QWORD *v43; // x0
  _QWORD *v44; // x2
  __int64 v45; // x8
  _QWORD *v46; // x0
  _QWORD *v47; // x2
  __int64 v48; // x8
  _QWORD *v49; // x0
  _QWORD *v50; // x0
  __int64 v51; // x1
  int v52; // w20
  _QWORD *v53; // x0
  __int64 v54; // x8

  result = 4294967274LL;
  if ( a1 && a3 )
  {
    if ( (a2[4][96] & 1) == 0 )
    {
      v9 = (__int64)*a2;
      mutex_lock(a3 + 963);
      if ( v9 )
      {
        if ( a2 )
        {
          v11 = (__int64)*a2;
          v12 = **a2;
          if ( (unsigned int)(v12 - 6) > 0xFFFFFFFA )
          {
            v14 = raw_spin_lock_irqsave(a3 + 969);
            v15 = *((_DWORD *)a3 + 1898);
            raw_spin_unlock_irqrestore(a3 + 969, v14);
            if ( !v15 )
            {
              v3 = 0;
              v5 = v11 + 4;
              v4 = a3 + 950;
              _ReadStatusReg(SP_EL0);
              while ( 1 )
              {
                v17 = _kmalloc_cache_noprof(_drm_debug, 3520, 64);
                v4[v3] = v17;
                if ( !v17 || v17 > 0xFFFFFFFFFFFFF000LL )
                  goto LABEL_71;
                v18 = *(unsigned int *)(v5 + 4 * v3);
                v19 = *a3;
                *(_DWORD *)(v17 + 24) = v18;
                v20 = drm_framebuffer_lookup(v19, 0, v18);
                if ( !v20 )
                  goto LABEL_44;
                *(_QWORD *)v4[v3] = v20;
                *(_QWORD *)(v4[v3] + 8) = msm_framebuffer_bo(v20, 0);
                v21 = *(_QWORD *)(v4[v3] + 8);
                if ( !v21 )
                {
                  _drm_err("failed to get gem object\n");
                  goto LABEL_71;
                }
                if ( ((*(_DWORD *)(v21 + 216) + 4095) & 0xFFFFF000) <= 0x46C6 )
                {
                  _drm_err("Invalid buffer size\n");
                  goto LABEL_71;
                }
                *(_QWORD *)(v4[v3] + 16) = msm_gem_smmu_address_space_get(*a3, 0);
                v22 = v4[v3];
                v23 = *(_QWORD *)(v22 + 16);
                if ( v23 == -19 )
                {
                  *(_QWORD *)(v22 + 16) = 0;
                  _drm_dev_dbg(0, 0, 0, "IOMMU not present, relying on VRAM\n");
                  v22 = v4[v3];
                  v23 = *(_QWORD *)(v22 + 16);
                }
                else if ( !v23 || v23 >= 0xFFFFFFFFFFFFF001LL )
                {
                  *(_QWORD *)(v22 + 16) = 0;
                  _drm_err("failed to get aspace\n");
                  goto LABEL_71;
                }
                iova = msm_gem_get_iova(*(_QWORD *)(v22 + 8), v23, v22 + 32);
                if ( iova )
                {
                  _drm_err("failed to get the iova ret %d\n", iova);
                  goto LABEL_71;
                }
                *(_QWORD *)(v4[v3] + 40) = msm_gem_get_vaddr(*(_QWORD *)(v4[v3] + 8));
                v25 = v4[v3];
                v26 = *(_QWORD *)(v25 + 40);
                if ( !v26 || v26 >= 0xFFFFFFFFFFFFF001LL )
                {
                  _drm_err("failed to get kva\n");
                  goto LABEL_71;
                }
                ++v3;
                *(_DWORD *)(v25 + 28) = ((*(_DWORD *)(v25 + 32) + 255) & 0xFFFFFF00) - *(_DWORD *)(v25 + 32);
                if ( v12 == v3 )
                {
                  v32 = raw_spin_lock_irqsave(a3 + 969);
                  v33 = (_QWORD *)a3[955];
                  v34 = v32;
                  v35 = a3 + 955;
                  v36 = a3[950];
                  v37 = (_QWORD *)(v36 + 48);
                  if ( (__int64 *)v33[1] != a3 + 955 || v37 == v35 || v33 == v37 )
                  {
                    _list_add_valid_or_report(v37, a3 + 955);
                    if ( (_DWORD)v12 != 1 )
                      goto LABEL_53;
                  }
                  else
                  {
                    v33[1] = v37;
                    *(_QWORD *)(v36 + 48) = v33;
                    *(_QWORD *)(v36 + 56) = v35;
                    *v35 = v37;
                    if ( (_DWORD)v12 != 1 )
                    {
LABEL_53:
                      v38 = (_QWORD *)a3[955];
                      v39 = a3[951];
                      v40 = (_QWORD *)(v39 + 48);
                      if ( (_QWORD *)v38[1] != v35 || v40 == v35 || v38 == v40 )
                      {
                        _list_add_valid_or_report(v40, v35);
                        if ( (_DWORD)v12 != 2 )
                          goto LABEL_57;
                      }
                      else
                      {
                        v38[1] = v40;
                        *(_QWORD *)(v39 + 48) = v38;
                        *(_QWORD *)(v39 + 56) = v35;
                        *v35 = v40;
                        if ( (_DWORD)v12 != 2 )
                        {
LABEL_57:
                          v41 = (_QWORD *)a3[955];
                          v42 = a3[952];
                          v43 = (_QWORD *)(v42 + 48);
                          if ( (_QWORD *)v41[1] != v35 || v43 == v35 || v41 == v43 )
                          {
                            _list_add_valid_or_report(v43, v35);
                            if ( (_DWORD)v12 != 3 )
                              goto LABEL_61;
                          }
                          else
                          {
                            v41[1] = v43;
                            *(_QWORD *)(v42 + 48) = v41;
                            *(_QWORD *)(v42 + 56) = v35;
                            *v35 = v43;
                            if ( (_DWORD)v12 != 3 )
                            {
LABEL_61:
                              v44 = (_QWORD *)a3[955];
                              v45 = a3[953];
                              v46 = (_QWORD *)(v45 + 48);
                              if ( (_QWORD *)v44[1] != v35 || v46 == v35 || v44 == v46 )
                              {
                                _list_add_valid_or_report(v46, v35);
                                if ( (_DWORD)v12 != 4 )
                                {
LABEL_65:
                                  v47 = (_QWORD *)a3[955];
                                  v48 = a3[954];
                                  v49 = (_QWORD *)(v48 + 48);
                                  if ( (_QWORD *)v47[1] != v35 || v49 == v35 || v47 == v49 )
                                  {
                                    _list_add_valid_or_report(v49, v35);
                                  }
                                  else
                                  {
                                    v47[1] = v49;
                                    *(_QWORD *)(v48 + 48) = v47;
                                    *(_QWORD *)(v48 + 56) = v35;
                                    *v35 = v49;
                                  }
                                }
                              }
                              else
                              {
                                v44[1] = v46;
                                *(_QWORD *)(v45 + 48) = v44;
                                *(_QWORD *)(v45 + 56) = v35;
                                *v35 = v46;
                                if ( (_DWORD)v12 != 4 )
                                  goto LABEL_65;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  *((_DWORD *)a3 + 1898) = v12;
                  raw_spin_unlock_irqrestore(a3 + 969, v34);
                  goto LABEL_79;
                }
              }
            }
            _drm_dev_dbg(0, 0, 0, "%d ltm_buffers already allocated\n", *((_DWORD *)a3 + 1898));
          }
          else
          {
            _drm_err("invalid buffer size %d\n", v12);
          }
        }
        else
        {
          _drm_err("invalid parameters sde_crtc %pK cfg %pK\n", a3, nullptr);
        }
      }
      else
      {
        v13 = raw_spin_lock_irqsave(a3 + 969);
        if ( *((_BYTE *)a3 + 7672) == 1 )
        {
          raw_spin_unlock_irqrestore(a3 + 969, v13);
          _drm_err("cannot free LTM buffers when hist is enabled\n");
        }
        else
        {
          v16 = *((_DWORD *)a3 + 1898);
          if ( v16 )
          {
            if ( (__int64 *)a3[957] == a3 + 957 )
            {
              *((_DWORD *)a3 + 1898) = 0;
              a3[955] = (__int64)(a3 + 955);
              a3[956] = (__int64)(a3 + 955);
              a3[957] = (__int64)(a3 + 957);
              a3[958] = (__int64)(a3 + 957);
              raw_spin_unlock_irqrestore(a3 + 969, v13);
              v27 = a3[950];
              if ( v27 )
              {
                msm_gem_put_vaddr(*(_QWORD *)(v27 + 8));
                drm_mode_object_put(*(_QWORD *)a3[950] + 24LL);
                msm_gem_put_iova(*(_QWORD *)(a3[950] + 8), *(_QWORD *)(a3[950] + 16));
                kfree(a3[950]);
                a3[950] = 0;
                if ( v16 != 1 )
                {
                  v28 = a3[951];
                  if ( v28 )
                  {
                    msm_gem_put_vaddr(*(_QWORD *)(v28 + 8));
                    drm_mode_object_put(*(_QWORD *)a3[951] + 24LL);
                    msm_gem_put_iova(*(_QWORD *)(a3[951] + 8), *(_QWORD *)(a3[951] + 16));
                    kfree(a3[951]);
                    a3[951] = 0;
                    if ( v16 != 2 )
                    {
                      v29 = a3[952];
                      if ( v29 )
                      {
                        msm_gem_put_vaddr(*(_QWORD *)(v29 + 8));
                        drm_mode_object_put(*(_QWORD *)a3[952] + 24LL);
                        msm_gem_put_iova(*(_QWORD *)(a3[952] + 8), *(_QWORD *)(a3[952] + 16));
                        kfree(a3[952]);
                        a3[952] = 0;
                        if ( v16 != 3 )
                        {
                          v30 = a3[953];
                          if ( v30 )
                          {
                            msm_gem_put_vaddr(*(_QWORD *)(v30 + 8));
                            drm_mode_object_put(*(_QWORD *)a3[953] + 24LL);
                            msm_gem_put_iova(*(_QWORD *)(a3[953] + 8), *(_QWORD *)(a3[953] + 16));
                            kfree(a3[953]);
                            a3[953] = 0;
                            if ( v16 != 4 )
                            {
                              v31 = a3[954];
                              if ( v31 )
                              {
                                msm_gem_put_vaddr(*(_QWORD *)(v31 + 8));
                                drm_mode_object_put(*(_QWORD *)a3[954] + 24LL);
                                msm_gem_put_iova(*(_QWORD *)(a3[954] + 8), *(_QWORD *)(a3[954] + 16));
                                kfree(a3[954]);
                                a3[954] = 0;
                                if ( v16 != 5 )
                                {
                                  __break(0x5512u);
LABEL_44:
                                  _drm_err("unknown framebuffer ID %d\n", *(_DWORD *)(v5 + 4 * v3));
LABEL_71:
                                  if ( (_DWORD)v3 )
                                  {
                                    v50 = (_QWORD *)v4[v3];
                                    v51 = v50[2];
                                    if ( v51 )
                                    {
                                      msm_gem_put_iova(v50[1], v51);
                                      v50 = (_QWORD *)v4[v3];
                                    }
                                    if ( v50[1] )
                                    {
                                      msm_gem_put_vaddr(v50[1]);
                                      v50 = (_QWORD *)v4[v3];
                                    }
                                    if ( *v50 )
                                    {
                                      drm_mode_object_put(*v50 + 24LL);
                                      v50 = (_QWORD *)v4[v3];
                                    }
                                    kfree(v50);
                                    v4[v3] = 0;
                                    if ( (_DWORD)v3 != 1 )
                                    {
                                      v52 = v3 - 1;
                                      do
                                      {
                                        msm_gem_put_iova(0x10CE3C0029ED90LL, 0x29ED840029EDFALL);
                                        v53 = (_QWORD *)v4[v3];
                                        v54 = v53[1];
                                        if ( v54 )
                                        {
                                          msm_gem_put_vaddr(v54);
                                          v53 = (_QWORD *)v4[v3];
                                        }
                                        if ( *v53 )
                                        {
                                          drm_mode_object_put(*v53 + 24LL);
                                          v53 = (_QWORD *)v4[v3];
                                        }
                                        kfree(v53);
                                        --v52;
                                        v4[v3] = 0;
                                      }
                                      while ( v52 );
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else
            {
              raw_spin_unlock_irqrestore(a3 + 969, v13);
              _drm_err("ltm_buf_busy is not empty\n");
            }
          }
          else
          {
            raw_spin_unlock_irqrestore(a3 + 969, v13);
          }
        }
      }
LABEL_79:
      mutex_unlock(a3 + 963);
    }
    return 0;
  }
  return result;
}
