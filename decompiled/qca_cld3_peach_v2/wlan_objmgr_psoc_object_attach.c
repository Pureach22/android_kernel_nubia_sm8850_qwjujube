__int64 __fastcall wlan_objmgr_psoc_object_attach(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 StatusReg; // x9
  __int64 v4; // x8
  __int64 v5; // x9
  unsigned int v6; // w20
  __int64 v7; // x10

  v2 = g_umac_glb_obj;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v2 + 11720);
  }
  else
  {
    raw_spin_lock_bh(v2 + 11720);
    *(_QWORD *)(v2 + 11728) |= 1uLL;
  }
  v4 = g_umac_glb_obj;
  v5 = *(_QWORD *)g_umac_glb_obj;
  if ( *(_QWORD *)g_umac_glb_obj )
  {
    if ( *(_QWORD *)(g_umac_glb_obj + 8) )
    {
      if ( *(_QWORD *)(g_umac_glb_obj + 16) )
      {
        if ( *(_QWORD *)(g_umac_glb_obj + 24) )
        {
          if ( *(_QWORD *)(g_umac_glb_obj + 32) )
          {
            v6 = 16;
            goto LABEL_16;
          }
          v5 = 4;
        }
        else
        {
          v5 = 3;
        }
      }
      else
      {
        v5 = 2;
      }
    }
    else
    {
      v5 = 1;
    }
  }
  *(_QWORD *)(g_umac_glb_obj + 8 * v5) = a1;
  v6 = 0;
  v4 = g_umac_glb_obj;
  *(_BYTE *)(a1 + 48) = v5;
LABEL_16:
  v7 = *(_QWORD *)(v4 + 11728);
  if ( (v7 & 1) != 0 )
  {
    *(_QWORD *)(v4 + 11728) = v7 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v4 + 11720);
  }
  else
  {
    raw_spin_unlock(v4 + 11720);
  }
  return v6;
}
