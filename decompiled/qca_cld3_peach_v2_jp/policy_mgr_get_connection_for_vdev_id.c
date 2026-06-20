__int64 __fastcall policy_mgr_get_connection_for_vdev_id(__int64 a1, int a2)
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
  unsigned int v13; // w20

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v12 = comp_private_obj;
    qdf_mutex_acquire(comp_private_obj + 56);
    if ( (_DWORD)qword_81C458 == a2 && (qword_81C458 & 0x100000000LL) != 0 )
    {
      v13 = 0;
    }
    else if ( (_DWORD)qword_81C47C == a2 && (qword_81C47C & 0x100000000LL) != 0 )
    {
      v13 = 1;
    }
    else if ( (_DWORD)qword_81C4A0 == a2 && (qword_81C4A0 & 0x100000000LL) != 0 )
    {
      v13 = 2;
    }
    else if ( (_DWORD)qword_81C4C4 == a2 && (qword_81C4C4 & 0x100000000LL) != 0 )
    {
      v13 = 3;
    }
    else if ( (_DWORD)qword_81C4E8 == a2 && (qword_81C4E8 & 0x100000000LL) != 0 )
    {
      v13 = 4;
    }
    else
    {
      v13 = 5;
    }
    qdf_mutex_release(v12 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_get_connection_for_vdev_id");
    return 0;
  }
  return v13;
}
