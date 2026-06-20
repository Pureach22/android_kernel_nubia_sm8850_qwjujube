__int64 __fastcall msm_pcie_drv_rpmsg_probe(__int64 a1)
{
  mutex_lock(&unk_30D08);
  qword_30CB0 = a1;
  *(_QWORD *)(a1 + 152) = pcie_drv;
  mutex_unlock(&unk_30D08);
  queue_work_on(32, system_wq, &qword_30CB8);
  return 0;
}
