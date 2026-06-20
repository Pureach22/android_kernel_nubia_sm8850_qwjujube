__int64 __fastcall pmic_spmi_remove(__int64 a1)
{
  mutex_lock(&pmic_spmi_revid_lock);
  *(_QWORD *)(a1 + 152) = 0;
  return mutex_unlock(&pmic_spmi_revid_lock);
}
