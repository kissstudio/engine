/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
namespace minikin {

class MinikinFontSkia : public MinikinFont {
public:
    explicit MinikinFontSkia(sk_sp<SkTypeface> typeface);

    float GetHorizontalAdvance(uint32_t glyph_id,
        const MinikinPaint &paint) const;

    void GetBounds(MinikinRect* bounds, uint32_t glyph_id,
        const MinikinPaint& paint) const;

    const std::vector<minikin::FontVariation>& GetAxes() const {
        return mAxes;
    }
    const void* GetTable(uint32_t tag, size_t* size, MinikinDestroyFunc* destroy) const;

    SkTypeface *GetSkTypeface() const;

private:
    sk_sp<SkTypeface> mTypeface;
    std::vector<minikin::FontVariation> mAxes;
};

}  // namespace minikin
