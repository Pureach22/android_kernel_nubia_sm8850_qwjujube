__int64 __fastcall ufs_qcom_panic_handler(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w19

  v1 = *(_QWORD *)(a1 - 3136);
  v2 = *(_DWORD *)(*(_QWORD *)(v1 + 56) + 432LL);
  dev_err(*(_QWORD *)(v1 + 64), "......dumping ufs info .......\n");
  dev_err(*(_QWORD *)(v1 + 64), "UFS Host state=%d\n", *(_DWORD *)(v1 + 496));
  dev_err(*(_QWORD *)(v1 + 64), "outstanding reqs=0x%lx tasks=0x%lx\n", *(_QWORD *)(v1 + 128), *(_QWORD *)(v1 + 112));
  dev_err(*(_QWORD *)(v1 + 64), "saved_err=0x%x, saved_uic_err=0x%x\n", *(_DWORD *)(v1 + 680), *(_DWORD *)(v1 + 684));
  dev_err(*(_QWORD *)(v1 + 64), "Device power mode=%d, UIC link state=%d\n", *(_DWORD *)(v1 + 80), *(_DWORD *)(v1 + 84));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "PM in progress=%d, sys. suspended=%d\n",
    *(_DWORD *)(v1 + 96),
    *(unsigned __int8 *)(v1 + 3217));
  dev_err(*(_QWORD *)(v1 + 64), "Clk gate=%d\n", *(_DWORD *)(v1 + 2900));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "last_hibern8_exit_tstamp at %lld us, hibern8_exit_cnt=%d\n",
    *(_QWORD *)(v1 + 712) / 1000LL,
    *(_DWORD *)(v1 + 704));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "last intr at %lld us, last intr status=0x%x\n",
    *(_QWORD *)(v1 + 696) / 1000LL,
    *(_DWORD *)(v1 + 688));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "error handling flags=0x%x, req. abort count=%d\n",
    *(_DWORD *)(v1 + 500),
    *(_DWORD *)(v1 + 2684));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "hba->ufs_version=0x%x, Host capabilities=0x%x, caps=0x%x\n",
    *(_DWORD *)(v1 + 160),
    *(_DWORD *)(v1 + 136),
    *(_DWORD *)(v1 + 3000));
  dev_err(*(_QWORD *)(v1 + 64), "quirks=0x%x, dev. quirks=0x%x\n", *(_DWORD *)(v1 + 212), *(_DWORD *)(v1 + 220));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "[RX, TX]: gear=[%d, %d], lane[%d, %d], rate = %d\n",
    *(_DWORD *)(v1 + 2692),
    *(_DWORD *)(v1 + 2696),
    *(_DWORD *)(v1 + 2700),
    *(_DWORD *)(v1 + 2704),
    *(_DWORD *)(v1 + 2716));
  dev_err(*(_QWORD *)(v1 + 64), "UFS RPM level = %d\n", *(_DWORD *)(v1 + 88));
  dev_err(*(_QWORD *)(v1 + 64), "UFS SPM level = %d\n", *(_DWORD *)(v1 + 92));
  dev_err(
    *(_QWORD *)(v1 + 64),
    "host_blocked=%d\n host_failed =%d\n Host self-block=%d\n",
    v2,
    *(_DWORD *)(*(_QWORD *)(v1 + 56) + 436LL),
    (*(unsigned __int16 *)(*(_QWORD *)(v1 + 56) + 548LL) >> 2) & 1);
  dev_err(*(_QWORD *)(v1 + 64), "............. ufs dump complete ..........\n");
  return 1;
}
