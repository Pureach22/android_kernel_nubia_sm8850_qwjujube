__int64 __fastcall policy_mgr_get_mode_by_vdev_id(__int64 a1, unsigned __int8 a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 *v13; // x9
  unsigned int v14; // w20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    qdf_mutex_acquire(comp_private_obj + 56);
    if ( (_DWORD)qword_8D4F00 == a2 && (v13 = &pm_conc_connection_list, BYTE4(qword_8D4F00) == 1)
      || (_DWORD)qword_8D4F24 == a2 && (v13 = &qword_8D4F0C, (qword_8D4F24 & 0x100000000LL) != 0)
      || (_DWORD)qword_8D4F48 == a2 && (v13 = &qword_8D4F30, (qword_8D4F48 & 0x100000000LL) != 0)
      || (_DWORD)qword_8D4F6C == a2 && (v13 = &qword_8D4F54, (qword_8D4F6C & 0x100000000LL) != 0)
      || (_DWORD)qword_8D4F90 == a2 && (v13 = &qword_8D4F78, (qword_8D4F90 & 0x100000000LL) != 0) )
    {
      v14 = *(_DWORD *)v13;
    }
    else
    {
      v14 = 7;
    }
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_mode_by_vdev_id");
    return 7;
  }
  return v14;
}
