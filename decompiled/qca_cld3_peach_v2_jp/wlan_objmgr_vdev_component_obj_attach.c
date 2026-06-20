__int64 __fastcall wlan_objmgr_vdev_component_obj_attach(__int64 a1, unsigned int a2, __int64 a3, int a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  unsigned int v12; // w20
  int v13; // w9
  __int64 v14; // x22
  __int64 v15; // x8
  _DWORD *v16; // x9
  __int64 v17; // x1

  if ( a2 > 0x35 )
    return 38;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 1272);
  }
  else
  {
    raw_spin_lock_bh(a1 + 1272);
    *(_QWORD *)(a1 + 1280) |= 1uLL;
  }
  if ( !*(_QWORD *)(a1 + 616 + 8LL * a2) )
  {
    *(_QWORD *)(a1 + 616 + 8LL * a2) = a3;
    *(_DWORD *)(a1 + 4LL * a2 + 1048) = a4;
    v11 = *(_QWORD *)(a1 + 1280);
    if ( (v11 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 1280) = v11 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 1272);
    }
    else
    {
      raw_spin_unlock(a1 + 1272);
    }
    if ( *(_DWORD *)(a1 + 1264) == 3 )
    {
      v12 = wlan_objmgr_vdev_object_status(a1);
      if ( !v12 )
      {
        v13 = 1;
LABEL_18:
        v14 = -432;
        *(_DWORD *)(a1 + 1264) = v13;
        v15 = g_umac_glb_obj;
        do
        {
          v16 = *(_DWORD **)(v15 + v14 + 7816);
          if ( v16 )
          {
            v17 = *(_QWORD *)(v15 + v14 + 8248);
            if ( *(v16 - 1) != -1188329905 )
              __break(0x8229u);
            ((void (__fastcall *)(__int64, __int64, _QWORD))v16)(a1, v17, v12);
            v15 = g_umac_glb_obj;
          }
          v14 += 8;
        }
        while ( v14 );
        return 0;
      }
      if ( v12 == 16 )
      {
        v13 = 7;
        goto LABEL_18;
      }
    }
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 1280);
  if ( (v10 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 1280) = v10 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 1272);
  }
  else
  {
    raw_spin_unlock(a1 + 1272);
  }
  return 16;
}
