__int64 __fastcall cam_cdm_intf_component_bind(__int64 a1)
{
  __int64 v1; // x20
  unsigned int dt_properties; // w0
  unsigned int v3; // w21
  const char *v4; // x5
  __int64 v5; // x2
  __int64 v6; // x4
  __int64 v7; // x20
  int *v8; // x19
  _QWORD *v9; // x24
  unsigned __int64 v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = a1 - 16;
  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dt_properties = cam_cdm_intf_mgr_soc_get_dt_properties(a1 - 16, (__int64)cdm_mgr);
  if ( dt_properties )
  {
    v3 = dt_properties;
    v4 = "Failed to get dt properties";
    v5 = 1;
    v6 = 706;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      v5,
      "cam_cdm_intf_component_bind",
      v6,
      v4);
    goto LABEL_17;
  }
  mutex_lock(&cam_cdm_mgr_lock);
  _mutex_init(&unk_394240, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394270 = 0;
  qword_394278 = 0;
  qword_394280 = 0;
  _mutex_init(&unk_394288, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_3942B8 = 0;
  qword_3942C0 = 0;
  qword_3942C8 = 0;
  _mutex_init(&unk_3942D0, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394300 = 0;
  qword_394308 = 0;
  qword_394310 = 0;
  _mutex_init(&unk_394318, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394348 = 0;
  qword_394350 = 0;
  qword_394358 = 0;
  _mutex_init(&unk_394360, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394390 = 0;
  qword_394398 = 0;
  qword_3943A0 = 0;
  _mutex_init(&unk_3943A8, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_3943D8 = 0;
  qword_3943E0 = 0;
  qword_3943E8 = 0;
  _mutex_init(&unk_3943F0, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394420 = 0;
  qword_394428 = 0;
  qword_394430 = 0;
  _mutex_init(&unk_394438, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394468 = 0;
  qword_394470 = 0;
  qword_394478 = 0;
  _mutex_init(&unk_394480, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_3944B0 = 0;
  qword_3944B8 = 0;
  qword_3944C0 = 0;
  _mutex_init(&unk_3944C8, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_3944F8 = 0;
  qword_394500 = 0;
  qword_394508 = 0;
  _mutex_init(&unk_394510, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394540 = 0;
  qword_394548 = 0;
  qword_394550 = 0;
  _mutex_init(&unk_394558, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394588 = 0;
  qword_394590 = 0;
  qword_394598 = 0;
  _mutex_init(&unk_3945A0, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_3945D0 = 0;
  qword_3945D8 = 0;
  qword_3945E0 = 0;
  _mutex_init(&unk_3945E8, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394618 = 0;
  qword_394620 = 0;
  qword_394628 = 0;
  _mutex_init(&unk_394630, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_394660 = 0;
  qword_394668 = 0;
  qword_394670 = 0;
  _mutex_init(&unk_394678, "&cdm_mgr.nodes[i].lock", &cam_cdm_intf_component_bind___key);
  dword_3946A8 = 0;
  qword_3946B0 = 0;
  qword_3946B8 = 0;
  cdm_mgr[0] = 1;
  dword_39423C = 0;
  mutex_unlock(&cam_cdm_mgr_lock);
  v3 = cam_virtual_cdm_probe(v1);
  if ( v3 )
  {
    mutex_lock(&cam_cdm_mgr_lock);
    v7 = 0;
    cdm_mgr[0] = 0;
    v8 = &dword_394270;
    do
    {
      v9 = v8 + 2;
      if ( *((_QWORD *)v8 + 1) || *((_QWORD *)v8 + 2) || *v8 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_cdm_intf_component_bind",
          727,
          "Valid node present in index=%d",
          v7);
      ++v7;
      *v8 = 0;
      v8 += 18;
      *v9 = 0;
      v9[1] = 0;
    }
    while ( v7 != 16 );
    mutex_unlock(&cam_cdm_mgr_lock);
  }
  v11[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("cdm", v11) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_debugfs_init",
      686,
      "DebugFS could not create directory!");
  }
  else
  {
    qword_3946C0 = v11[0];
    debugfs_create_file("test_irq_line", 420, v11[0], 0, &cam_cdm_irq_line_test);
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    v4 = "CDM Intf component bound successfully";
    v5 = 4;
    v6 = 738;
    goto LABEL_3;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v3;
}
