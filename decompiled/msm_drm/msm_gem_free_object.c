__int64 __fastcall msm_gem_free_object(_QWORD *a1)
{
  __int64 v2; // x10
  __int64 v3; // x20
  _QWORD *v4; // x8
  _QWORD *v5; // x0
  __int64 v6; // x9
  __int64 v7; // x8
  _QWORD *v8; // x8
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 result; // x0
  _QWORD v12[3]; // [xsp+8h] [xbp-18h] BYREF

  v12[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[49];
  v3 = *(_QWORD *)(a1[1] + 56LL);
  v12[0] = a1[54];
  v12[1] = 0;
  if ( v2 )
    __break(0x800u);
  mutex_lock(v3 + 640);
  v4 = (_QWORD *)a1[48];
  v5 = a1 + 47;
  if ( (_QWORD *)*v4 == a1 + 47 && (v6 = *v5, *(_QWORD **)(*v5 + 8LL) == v5) )
  {
    *(_QWORD *)(v6 + 8) = v4;
    *v4 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(v5);
  }
  a1[47] = 0xDEAD000000000100LL;
  a1[48] = 0xDEAD000000000122LL;
  mutex_unlock(v3 + 640);
  mutex_lock(a1 + 68);
  put_iova((__int64)a1);
  v7 = a1[76];
  if ( v7 )
  {
    mutex_lock(v7 + 320);
    msm_gem_remove_obj_from_aspace_active_list(a1[76], a1);
    mutex_unlock(a1[76] + 320LL);
  }
  v8 = (_QWORD *)a1[30];
  if ( v8 )
  {
    if ( a1[54] )
      dma_buf_vunmap_unlocked(*v8, v12);
    v9 = a1[52];
    if ( v9 )
      kvfree(v9);
    drm_prime_gem_destroy(a1, a1[53]);
  }
  else
  {
    msm_gem_vunmap_locked((__int64)a1);
    if ( a1[52] )
    {
      if ( a1[53] )
      {
        sg_free_table();
        kfree(a1[53]);
      }
      if ( a1[67] )
      {
        v10 = *(_QWORD *)(a1[1] + 56LL);
        raw_spin_lock(v10 + 5488);
        drm_mm_remove_node(a1[67]);
        raw_spin_unlock(v10 + 5488);
        kvfree(a1[52]);
      }
      else
      {
        drm_gem_put_pages(a1, a1[52], 1, 0);
      }
      a1[52] = 0;
    }
  }
  if ( (_QWORD *)a1[58] == a1 + 59 )
    dma_resv_fini();
  drm_gem_object_release(a1);
  mutex_unlock(a1 + 68);
  result = kfree(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
