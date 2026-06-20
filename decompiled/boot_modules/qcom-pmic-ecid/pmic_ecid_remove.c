__int64 __fastcall pmic_ecid_remove(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 168);
  device_remove_file(*(_QWORD *)v1, &dev_attr_ecid);
  device_destroy(&pmic_ecid_class, *(unsigned int *)(v1 + 40));
  return ida_free(&pmic_ecid_dev_ida, *(unsigned int *)(v1 + 40));
}
